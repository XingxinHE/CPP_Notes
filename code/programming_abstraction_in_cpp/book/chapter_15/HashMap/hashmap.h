/*
 * File: hashmap.h
 * ---------------
 * This interface exports the HashMap class, which maintains a collection
 * of key-value pairs using a hashtable as the underlying data structure.
 */

#ifndef _hashmap_h
#define _hashmap_h

#include <cstdlib>
#include <string>

/*
 * Class: HashMap<KeyType,ValueType>
 * ---------------------------------
 * The HashMap class maintains an association between keys and values.
 * The types used for keys and values are specified as template parameters,
 * which makes it possible to use this structure with any data type.
 */

class HashMap {

public:

/*
 * Constructor: HashMap
 * Usage: HashMap<KeyType,ValueType> map;
 * --------------------------------------
 * Initializes a new empty map that associates keys and values of the
 * specified types.  The type used for the key must define the == operator,
 * and there must be a free function with the following signature:
 *
 *     int hashCode(KeyType key);
 *
 * that returns a positive integer determined by the key.  This interface
 * exports hashCode functions for string and the C++ primitive types.
 */

   HashMap();

/*
 * Destructor: ~HashMap
 * Usage: (usually implicit)
 * -------------------------
 * Frees any heap storage associated with this map.
 */

   ~HashMap();

/*
 * Method: size
 * Usage: int nEntries = map.size();
 * ---------------------------------
 * Returns the number of entries in this map.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (map.isEmpty()) . . .
 * -------------------------------
 * Returns true if this map contains no entries.
 */

   bool isEmpty() const;

/*
 * Method: get
 * Usage: ValueType value = map.get(key);
 * --------------------------------------
 * Returns the value associated with key in this map.  If key is not
 * found, the get method signals an error.
 */

   std::string get(const std::string &_key) const;

/*
 * Method: put
 * Usage: map.put(key, value);
 * ---------------------------
 * Associates key with value in this map.  Any previous value associated
 * with key is replaced by the new value.
 */

   void put(const std::string &_key, const std::string &_value);

/*
 * Method: containsKey
 * Usage: if (map.containsKey(key)) . . .
 * --------------------------------------
 * Returns true if there is an entry for key in this map.
 */

   bool containsKey(std::string _key) const;

/*
 * Method: remove
 * Usage: map.remove(key);
 * -------------------
 * Removes the key from the hashmap.
 */

   void remove(std::string _key);


/*
 * Method: clear
 * Usage: map.clear();
 * -------------------
 * Removes all entries from this map.
 */

   void clear();

/*
 * Operator: [], set version
 * Usage: openWith["cpp"] = "visual studio";
 * -----------------------------------------
 * Set the key-value pair in indexing style.
 */

   std::string& operator[](std::string _key);

/*
 * Operator: [], get version
 * Usage: openWith["cpp"] = "visual studio";
 * -----------------------------------------
 * Get the key-value pair in indexing style.
 */

   std::string operator[](std::string key) const;


private:

/* Node Struct */
    struct Node
    {
        std::string key;
        std::string value;
        Node *next;
        Node(std::string _key, std::string _value)
            :key(_key), value(_value), next(nullptr)
        {
        }
    };

/* Constant */
    static const int INITIAL_BUCKET = 10;
    static const int HASH_SEED = 5381;               // Starting point for first cycle
    static const int HASH_MULTIPLIER = 33;           // Multiplier for each cycle
    static const int HASH_MASK = unsigned(-1) >> 1;  // All 1 bits except the sign

/* Members */
   Node **m_nodeArray;
   int m_count;
   int m_bucket;
   double m_loadFactor;

/* Private Methods */
/*
 * Method: getBucket
 * Usage: int bucket = getBucket(hashCode);
 * ----------------------------------------
 * Return the index of bucket from the hash code.
 */

   int getBucket(const int _code) const
   {
      return _code % m_bucket;
   }

/*
 * Method: hashCode
 * Usage: int code = hashCode(key);
 * --------------------------------
 * Return the hash code of a string.
 */

   int hashCode(const std::string &_key) const
   {
      unsigned hash = HASH_SEED;
      int n = _key.length();
      for (int i = 0; i < n; i++)
      {
         hash = HASH_MULTIPLIER * hash + _key[i];
      }
      return int(hash & HASH_MASK);
   }

/*
 * Method: findNode
 * Usage: Node* node = findNode(bucket, key);
 * ------------------------------------------
 * Return the pointer of found key.
 */

   Node* findNode(int bucket, std::string _key) const
   {
      Node *start = m_nodeArray[bucket];
      while(start != nullptr)
      {
         if(start->key == _key)
         {
            break;
         }
         else
         {
            start = start->next;
         }
      }
      return start;
   }

};




#endif