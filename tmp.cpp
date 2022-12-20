void deleteSet(string setName) {
    sets.erase(setName);
}
set intersectSets(vector<string> setNames) {
    set intersection;
    if (setNames.size() > 0) {
        set tmp = sets[setNames[0]];
        for (int i = 1; i < setNames.size(); i++) {
            set currentSet = sets[setNames[i]];
            set_intersection(tmp.values.begin(), tmp.values.end(), 
                             currentSet.values.begin(), currentSet.values.end(),
                             inserter(intersection.values, intersection.values.begin()));
            tmp = intersection;
        }
    }
    return intersection;
}
set unionSets(vector<string> setNames) {
    set unionSet;
    for (int i = 0; i < setNames.size(); i++) {
        set currentSet = sets[setNames[i]];
        set_union(unionSet.values.begin(), unionSet.values.end(), 
                  currentSet.values.begin(), currentSet.values.end(),
                  inserter(unionSet.values, unionSet.values.begin()));
    }
    return unionSet;
}
void sortSet(string setName, bool ascending) {
    set currentSet = sets[setName];
    if (ascending) {
        sort(currentSet.values.begin(), currentSet.values.end());
    } else {
        sort(currentSet.values.rbegin(), currentSet.values.rend());
    }
    sets[setName] = currentSet;
}
bool isSubset(string setName, string subsetName) {
    set currentSet = sets[setName];
    set subset = sets[subsetName];
    return includes(currentSet.values.begin(), currentSet.values.end(), 
                    subset.values.begin(), subset.values.end());
}
int minValue(string setName) {
    set currentSet = sets[setName];
    return *min_element(currentSet.values.begin(), currentSet.values.end());
}

int maxValue(string setName) {
    set currentSet = sets[setName];
    return *max_element(currentSet.values.begin(), currentSet.values.end());
}
bool containsValue(string setName, int value) {
    set currentSet = sets[setName];
    return binary_search(currentSet.values.begin(), currentSet.values.end(), value);
}
