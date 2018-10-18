# cag

## File class

The library has a **File** class to simplify reading and writing with files

- File::File(string path)
- string File::Read()
- bool File::Write(string to_file)

## line_tool class

A **line_tool** class includes:

`inline void rtrim(string& s, const char* t)`

`inline void ltrim(string& s, const char* t)`

`inline void trim(string& s, const char* t)`

`bool line_tool::split_line(
                                string& in, 
                                string delim, 
                                pair<string, string>& out, 
                                unsigned long long int line_start)`
                                
`void line_tool::get_lines(string& in, list<string>& out)`

`void line_tool::search_all(
                                const string& str_in, 
                                const string& to_find, 
                                set<uint64_t>& result_pos)`
                                
`void line_tool::find_and_replace(
                                    string& source, 
                                    string const& find, 
                                    string const& replace)`
                   
## Path class
                                    
A **Path** class is allowing to unify strings with path. Its public methods are:

`explicit Path(const string& path_str);`

`string get_string() const`

`Path& operator=(const Path& other);`

`friend ostream& operator<<(ostream& out, const Path& p);`

 