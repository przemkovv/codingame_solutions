#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 std::map<string, string> mime_types;
 
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string ext; // file extension
        string MT; // MIME type.
        cin >> ext>> MT; cin.ignore();
        transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        mime_types.emplace(make_pair(ext, MT));
    }
    
    for (int i = 0; i < Q; i++) {
        string mime_type = "UNKNOWN";
        string name; // One file name per line.
        getline(cin, name);
        
        auto dot_position = find(name.rbegin(), name.rend(), '.');
        auto ext_length = distance( name.rbegin(), dot_position);
        if (ext_length < name.length() ) {
            string ext;
            copy(name.end()-ext_length, name.end(),  std::back_inserter(ext));
            transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
            if (mime_types.find(ext) != mime_types.end()) {
                mime_type = mime_types.at(ext);
            }
        }
        
        cout << mime_type << endl;
        
        
    }

}
