
extern void test_extern(char* string);

extern int some_cpp_func( int magic_num );

int
main( int argc, char** argv )
{
    test_extern( "Hello world" );
    some_cpp_func( 13 );
}
