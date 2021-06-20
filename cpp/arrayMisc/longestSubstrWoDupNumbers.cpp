//
// Find longest substring without repeating numbers
//

vector<int> longestNonRepeatSubstring(vector<int> arr) {
    // Write your code here.
	vector<int> result{};
	map<int, int> map;		// map<elem, position>
	int start = 0;
	int longest = 0;

	for (int c : arr) cout << c << ",";
	cout << endl;
	for (int i = 0; i < arr.size(); i++) {
		auto itr = map.find(arr[i]);
		if (itr != map.end())	{ 						// check if we have seen this arr[i] elem
			longest = max(longest, i - start);
			start = max(start, itr->second+1);	// yeah, seen it, start new substring
			map[arr[i]] = i;								// forget prev seen
			cout << arr[i] << ", " << start << ", " << longest << endl;
		}
		else
			map.insert(make_pair(arr[i], i));		// update last seen position of this char
	}
	
	cout << start << ":" << longest << endl;
	
	for (int i = start; i < start+longest; i++ ) {
		cout << arr[i] << ",";
		result.push_back(arr[i]);
	}
	
  return result;
}



