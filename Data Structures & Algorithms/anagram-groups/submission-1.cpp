class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs)
        {
            string key=s;
            sort(key.begin(),key.end());
           mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& pair:mp)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
// # Unordered Map in C++

// ## 1. What is an `unordered_map`?

// An `unordered_map` stores data in **key-value pairs**.

// ```cpp
// unordered_map<KeyType, ValueType> name;
// ```

// Example:

// ```cpp
// unordered_map<string, int> mp;
// ```

// This means:

// ```text
// KEY       VALUE
// "apple" →  5
// "mango" →  10
// ```

// Here:

// * `string` → type of the **key**
// * `int` → type of the **value**
// * `mp` → name of the map

// `mp` is just a variable name. It commonly means "map".

// ---

// # 2. Why use `unordered_map`?

// It is useful when we want to quickly find a value using a key.

// For example:

// ```cpp
// mp["apple"] = 5;
// ```

// Now:

// ```cpp
// cout << mp["apple"];
// ```

// gives:

// ```text
// 5
// ```

// Average time for insertion/search/deletion:

// ```text
// O(1)
// ```

// ---

// # 3. Basic Operations

// ### Create

// ```cpp
// unordered_map<string, int> mp;
// ```

// ### Insert

// ```cpp
// mp["apple"] = 5;
// mp["banana"] = 10;
// ```

// Map:

// ```text
// "apple"  → 5
// "banana" → 10
// ```

// ### Access

// ```cpp
// cout << mp["apple"];
// ```

// Output:

// ```text
// 5
// ```

// ### Update

// ```cpp
// mp["apple"] = 20;
// ```

// Now:

// ```text
// "apple" → 20
// ```

// ### Check if key exists

// ```cpp
// if(mp.find("apple") != mp.end())
// ```

// This means:

// > `"apple"` exists in the map.

// ### Delete

// ```cpp
// mp.erase("apple");
// ```

// ---

// # 4. `unordered_map` with frequency counting

// One of the most common uses is **counting frequencies**.

// Example:

// ```text
// nums = [1, 2, 2, 3, 1, 2]
// ```

// Code:

// ```cpp
// unordered_map<int, int> mp;

// for(int x : nums) {
//     mp[x]++;
// }
// ```

// Result:

// ```text
// 1 → 2
// 2 → 3
// 3 → 1
// ```

// Why does this work?

// Initially:

// ```text
// mp[1] = 0
// ```

// After:

// ```cpp
// mp[1]++;
// ```

// it becomes:

// ```text
// mp[1] = 1
// ```

// Every time we see `1`, its count increases.

// ---

// # 5. `unordered_map` with vectors

// We can also store a **vector as the value**.

// ```cpp
// unordered_map<string, vector<string>> mp;
// ```

// This means:

// ```text
// KEY (string) → VALUE (vector of strings)
// ```

// Example:

// ```text
// "aet" → ["eat", "tea", "ate"]
// "ant" → ["tan", "nat"]
// "abt" → ["bat"]
// ```

// This is used in **Group Anagrams**.

// ---

// # 6. Group Anagrams Example

// Input:

// ```text
// ["eat", "tea", "tan", "ate", "nat", "bat"]
// ```

// Sort every word to create a common key:

// ```text
// eat → aet
// tea → aet
// tan → ant
// ate → aet
// nat → ant
// bat → abt
// ```

// Then:

// ```cpp
// unordered_map<string, vector<string>> mp;

// for(string s : strs) {

//     string key = s;

//     sort(key.begin(), key.end());

//     mp[key].push_back(s);
// }
// ```

// The map becomes:

// ```text
// "aet" → ["eat", "tea", "ate"]
// "ant" → ["tan", "nat"]
// "abt" → ["bat"]
// ```

// ### Important:

// ```cpp
// mp[key].push_back(s);
// ```

// means:

// > Find the vector associated with `key` and add `s` to that vector.

// ---

// # 7. `first` and `second`

// When we loop through a map:

// ```cpp
// for(auto& pair : mp)
// ```

// each `pair` contains:

// ```text
// pair.first  → KEY
// pair.second → VALUE
// ```

// For Group Anagrams:

// ```text
// "aet" → ["eat", "tea", "ate"]
// ```

// Therefore:

// ```cpp
// pair.first
// ```

// is:

// ```text
// "aet"
// ```

// and:

// ```cpp
// pair.second
// ```

// is:

// ```text
// ["eat", "tea", "ate"]
// ```

// ---

// # 8. Loop through an `unordered_map`

// ```cpp
// for(auto& pair : mp) {
//     cout << pair.first;
//     cout << pair.second;
// }
// ```

// Conceptually:

// ```text
// for each key-value pair in mp:
//         get the key using pair.first
//         get the value using pair.second
// ```

// ### What does `auto` mean?

// ```cpp
// auto
// ```

// means:

// > Let C++ automatically determine the data type.

// ### What does `&` mean?

// ```cpp
// auto& pair
// ```

// means `pair` refers to the existing element instead of creating a copy.

// For basic understanding, remember:

// ```cpp
// for(auto& pair : mp)
// ```

// =

// > Go through every key-value pair in the map.

// ---

// # 9. Important Difference: `map` vs `unordered_map`

// ### `map`

// ```cpp
// map<int, int> mp;
// ```

// * Keys are stored in sorted order
// * Search/insert/delete: `O(log n)`

// ### `unordered_map`

// ```cpp
// unordered_map<int, int> mp;
// ```

// * Keys are NOT stored in sorted order
// * Average search/insert/delete: `O(1)`

// For most NeetCode problems where you need **fast lookup**, `unordered_map` is commonly used.

// ---

// # 10. Most Important Patterns to Remember

// ### Frequency counting

// ```cpp
// unordered_map<int, int> mp;

// for(int x : nums) {
//     mp[x]++;
// }
// ```

// ### Checking existence

// ```cpp
// if(mp.find(x) != mp.end())
// ```

// ### Key → vector/group

// ```cpp
// unordered_map<string, vector<string>> mp;
// ```

// ### Add to a group

// ```cpp
// mp[key].push_back(value);
// ```

// ### Loop through map

// ```cpp
// for(auto& pair : mp) {
//     pair.first;   // key
//     pair.second;  // value
// }
// ```

// ---

// ## ⭐ One-line definition

// > **`unordered_map` is a key-value data structure that provides average `O(1)` time for searching, inserting, and deleting using a key.**

// ### Think of it like boxes:

// ```text
//           UNORDERED MAP

//      KEY              VALUE
//       ↓                 ↓
//    "aet"       →    [eat, tea, ate]
//    "ant"       →    [tan, nat]
//    "abt"       →    [bat]
// ```

// **Key = identifies the box**

// **Value = what's inside the box**

