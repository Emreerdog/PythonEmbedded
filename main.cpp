#ifdef _DEBUG
#define _DEBUG_WAS_DEFINED
#undef _DEBUG
#endif

#include "Python.h"
#include <iostream>

#ifdef _DEBUG_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_WAS_DEFINED
#endif

#pragma comment(lib, "python39.lib")
#pragma comment(lib, "python3.lib")

void pyPrintCWD() {
    PyObject* imports = PyImport_ImportModule("os");
    PyObject* func = PyObject_GetAttrString(imports, "getcwd");
    PyObject* result = PyObject_CallNoArgs(func);
    PyObject* temp_bytes = PyUnicode_AsEncodedString(result, "UTF-8", "strict");
    const char* printResult = PyBytes_AS_STRING(temp_bytes);
    Py_ssize_t i = PyObject_Size(result);
    std::cout << printResult << std::endl;

    Py_CLEAR(imports);
    Py_CLEAR(func);
    Py_CLEAR(result);
    Py_CLEAR(temp_bytes);
}

void pyGetSqrt(long num) {
    long _result = 0;
    PyObject* arguments = PyLong_FromLong(num);
    // PyTuple_SetItem(arguments, 0, PyLong_FromLong(num));
    PyObject* imports = PyImport_ImportModule("math");
    PyObject* func = PyObject_GetAttrString(imports, "sqrt");

    PyObject* result = PyObject_CallOneArg(func, arguments);
    _result = PyLong_AsLong(result);
    std::cout << _result << std::endl;
    // PyObject* temp_bytes = PyUnicode_AsEncodedString(result, "UTF-8", "strict");
    //const char* printResult = PyBytes_AS_STRING(temp_bytes);
    //std::cout << printResult << std::endl;
}

void pyWriteJson(const char* myjson) {
    PyObject* args = PyUnicode_FromString(myjson);

    PyObject* imports = PyImport_ImportModule("json");
    PyObject* func = PyObject_GetAttrString(imports, "loads");
    PyObject* parsedJSON = PyObject_CallOneArg(func, args);

    PyObject* func1 = PyObject_GetAttrString(imports, "dumps");
    PyObject* jsonResult = PyObject_CallOneArg(func1, parsedJSON);

    PyObject* temp_bytes = PyUnicode_AsEncodedString(jsonResult, "UTF-8", "strict");
    const char* printResult = PyBytes_AS_STRING(temp_bytes);

    std::cout << printResult << std::endl;

    Py_CLEAR(args);
    Py_CLEAR(imports);
    Py_CLEAR(func);
    Py_CLEAR(parsedJSON);
    Py_CLEAR(func1);
    Py_CLEAR(jsonResult);
    Py_CLEAR(temp_bytes);
}

void pyPrint(const char* word) {
    PyObject* myDics = PyEval_GetBuiltins();
    PyObject* itemDic = PyDict_GetItemString(myDics, "print");
    PyObject* args = PyUnicode_FromString(word);
    PyObject* function = PyObject_GetAttrString(itemDic, "print");
    PyObject* printBoy = PyObject_CallOneArg(function, args);
}

void pyPower(long x, long y) {
    PyObject* ourArgs = PyTuple_New(2);
    PyTuple_SetItem(ourArgs, 0, PyLong_FromLong(x));
    PyTuple_SetItem(ourArgs, 1, PyLong_FromLong(y));
    PyObject* imports = PyImport_ImportModule("math");
    PyObject* function = PyObject_GetAttrString(imports, "pow");
    PyObject* callFunc = PyObject_CallObject(function, ourArgs);
    long result = PyLong_AsLong(callFunc);
    std::cout << result << std::endl;
    Py_CLEAR(ourArgs);
    Py_CLEAR(imports);
    Py_CLEAR(function);
    Py_CLEAR(callFunc);
}

void pyNumpyboyz(long x, long y) {
    PyObject* ourArgs = PyTuple_New(2);
    PyTuple_SetItem(ourArgs, 0, PyLong_FromLong(x));
    PyTuple_SetItem(ourArgs, 1, PyLong_FromLong(y));
    PyObject* imports = PyImport_ImportModule("tkinter");
    //PyObject* function = PyObject_GetAttrString(imports, "add");
    //PyObject* callFunc = PyObject_CallObject(function, ourArgs);
    //long result = PyLong_AsLong(callFunc);
    //std::cout << result << std::endl;
}

int main(int argc, char* argv[]) {

    std::string setJson = "{ \"name\":\"John\", \"age\":30, \"city\":\"New York\" }";

    Py_Initialize();
    pyNumpyboyz(5, 16);
    Py_FinalizeEx();
    return 0;

}