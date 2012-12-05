#include <iostream>
#include <string>
using namespace std;
#include <v8.h>                                                     
	#pragma comment(lib,"WSock32.lib")          
	#pragma comment(lib,"ws2_32.lib")             
	#pragma comment(lib,"winmm.lib")             /**/
using namespace v8;    

void RUN(const char * jsstring){
  // Create a stack-allocated handle scope.
  HandleScope handle_scope;

  // Create a new context.
  Persistent<Context> context = Context::New();
  
  // Enter the created context for compiling and
  // running the hello world script. 
  Context::Scope context_scope(context);
  
  // Create a string containing the JavaScript source code.
  Handle<String> source = String::New(jsstring);

  // Compile the source code.
  Handle<Script> script = Script::Compile(source);
  
  // Run the script to get the result.
  Handle<Value> result = script->Run();
  
  // Dispose the persistent context.
  context.Dispose();

  // Convert the result to an ASCII string and print it.
  String::AsciiValue ascii(result);
  printf("%s\n", *ascii);
}

int main(int argc, char* argv[]) {
	string jsstring="";
	string jsstringpart="";
	char end=' ';
	do{
		do{
			getline(cin,jsstringpart);
			jsstring+=('\n'+(end+jsstringpart));
			//cout<<jsstring.c_str();
			end=cin.get();
		}while(end!='\n');
		RUN(jsstring.c_str());
	}while(true);
}

/*
https://developers.google.com/v8/get_started?hl=zh-CN
https://github.com/v8/v8
*/