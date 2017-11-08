begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: luaconf.h,v 1.176.1.2 2013/11/21 17:26:16 roberto Exp $ ** Configuration file for Lua ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lconfig_h
end_ifndef

begin_define
define|#
directive|define
name|lconfig_h
end_define

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|illumos
end_ifdef

begin_include
include|#
directive|include
file|<sys/int_fmtio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/_inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|ssize_t
name|lcompat_sprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int64_t
name|lcompat_strtoll
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int64_t
name|lcompat_pow
parameter_list|(
name|int64_t
parameter_list|,
name|int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** ================================================================== ** Search for "@@" to find all configurable definitions. ** =================================================================== */
end_comment

begin_comment
comment|/* @@ LUA_ANSI controls the use of non-ansi features. ** CHANGE it (define it) if you want Lua to avoid the use of any ** non-ansi feature or library. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUA_ANSI
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_ANSI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUA_ANSI
argument_list|)
operator|&&
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_WIN
end_define

begin_comment
comment|/* enable goodies for regular Windows platforms */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_WIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_DL_DLL
end_define

begin_define
define|#
directive|define
name|LUA_USE_AFORMAT
end_define

begin_comment
comment|/* assume 'printf' handles 'aA' specifiers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_USE_LINUX
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_USE_POSIX
end_define

begin_define
define|#
directive|define
name|LUA_USE_DLOPEN
end_define

begin_comment
comment|/* needs an extra library: -ldl */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_READLINE
end_define

begin_comment
comment|/* needs some extra libraries */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_STRTODHEX
end_define

begin_comment
comment|/* assume 'strtod' handles hex formats */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_AFORMAT
end_define

begin_comment
comment|/* assume 'printf' handles 'aA' specifiers */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_LONGLONG
end_define

begin_comment
comment|/* assume support for long long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_USE_MACOSX
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_USE_POSIX
end_define

begin_define
define|#
directive|define
name|LUA_USE_DLOPEN
end_define

begin_comment
comment|/* does not need -ldl */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_READLINE
end_define

begin_comment
comment|/* needs an extra library: -lreadline */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_STRTODHEX
end_define

begin_comment
comment|/* assume 'strtod' handles hex formats */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_AFORMAT
end_define

begin_comment
comment|/* assume 'printf' handles 'aA' specifiers */
end_comment

begin_define
define|#
directive|define
name|LUA_USE_LONGLONG
end_define

begin_comment
comment|/* assume support for long long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ LUA_USE_POSIX includes all functionality listed as X/Open System @* Interfaces Extension (XSI). ** CHANGE it (define it) if your system is XSI compatible. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_USE_POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_USE_MKSTEMP
end_define

begin_define
define|#
directive|define
name|LUA_USE_ISATTY
end_define

begin_define
define|#
directive|define
name|LUA_USE_POPEN
end_define

begin_define
define|#
directive|define
name|LUA_USE_ULONGJMP
end_define

begin_define
define|#
directive|define
name|LUA_USE_GMTIME_R
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ LUA_PATH_DEFAULT is the default path that Lua uses to look for @* Lua libraries. @@ LUA_CPATH_DEFAULT is the default path that Lua uses to look for @* C libraries. ** CHANGE them if your machine has a non-conventional directory ** hierarchy or if you want to install your libraries in ** non-conventional directories. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_comment
comment|/* ** In Windows, any exclamation mark ('!') in the path is replaced by the ** path of the directory of the executable file of the current process. */
end_comment

begin_define
define|#
directive|define
name|LUA_LDIR
value|"!\\lua\\"
end_define

begin_define
define|#
directive|define
name|LUA_CDIR
value|"!\\"
end_define

begin_define
define|#
directive|define
name|LUA_PATH_DEFAULT
define|\
value|LUA_LDIR"?.lua;"  LUA_LDIR"?\\init.lua;" \ 		LUA_CDIR"?.lua;"  LUA_CDIR"?\\init.lua;" ".\\?.lua"
end_define

begin_define
define|#
directive|define
name|LUA_CPATH_DEFAULT
define|\
value|LUA_CDIR"?.dll;" LUA_CDIR"loadall.dll;" ".\\?.dll"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_define
define|#
directive|define
name|LUA_VDIR
value|LUA_VERSION_MAJOR "." LUA_VERSION_MINOR "/"
end_define

begin_define
define|#
directive|define
name|LUA_ROOT
value|"/usr/local/"
end_define

begin_define
define|#
directive|define
name|LUA_LDIR
value|LUA_ROOT "share/lua/" LUA_VDIR
end_define

begin_define
define|#
directive|define
name|LUA_CDIR
value|LUA_ROOT "lib/lua/" LUA_VDIR
end_define

begin_define
define|#
directive|define
name|LUA_PATH_DEFAULT
define|\
value|LUA_LDIR"?.lua;"  LUA_LDIR"?/init.lua;" \ 		LUA_CDIR"?.lua;"  LUA_CDIR"?/init.lua;" "./?.lua"
end_define

begin_define
define|#
directive|define
name|LUA_CPATH_DEFAULT
define|\
value|LUA_CDIR"?.so;" LUA_CDIR"loadall.so;" "./?.so"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* @@ LUA_DIRSEP is the directory separator (for submodules). ** CHANGE it if your machine does not use "/" as the directory separator ** and is not Windows. (On Windows Lua automatically uses "\".) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_DIRSEP
value|"\\"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LUA_DIRSEP
value|"/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ LUA_ENV is the name of the variable that holds the current @@ environment, used to access global names. ** CHANGE it if you do not like this name. */
end_comment

begin_define
define|#
directive|define
name|LUA_ENV
value|"_ENV"
end_define

begin_comment
comment|/* @@ LUA_API is a mark for all core API functions. @@ LUALIB_API is a mark for all auxiliary library functions. @@ LUAMOD_API is a mark for all standard library opening functions. ** CHANGE them if you need to define those functions in some special way. ** For instance, if you want to create one Windows DLL with the core and ** the libraries, you may want to use the following definition (define ** LUA_BUILD_AS_DLL to get it). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_BUILD_AS_DLL
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_CORE
argument_list|)
operator|||
name|defined
argument_list|(
name|LUA_LIB
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|LUA_API
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_define
define|#
directive|define
name|LUA_API
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_define
define|#
directive|define
name|LUA_API
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* more often than not the libs go together with the core */
end_comment

begin_define
define|#
directive|define
name|LUALIB_API
value|LUA_API
end_define

begin_define
define|#
directive|define
name|LUAMOD_API
value|LUALIB_API
end_define

begin_comment
comment|/* @@ LUAI_FUNC is a mark for all extern functions that are not to be @* exported to outside modules. @@ LUAI_DDEF and LUAI_DDEC are marks for all extern (const) variables @* that are not to be exported to outside modules (LUAI_DDEF for @* definitions and LUAI_DDEC for declarations). ** CHANGE them if you need to mark them in some special way. Elf/gcc ** (versions 3.2 and later) mark them as "hidden" to optimize access ** when Lua is compiled as a shared library. Not all elf targets support ** this attribute. Unfortunately, gcc does not offer a way to check ** whether the target offers that support, and those without support ** give a warning about it. To avoid these warnings, change to the ** default definition. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|)
operator|>=
literal|302
operator|)
operator|&&
expr|\
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|LUAI_FUNC
value|__attribute__((visibility("hidden"))) extern
end_define

begin_define
define|#
directive|define
name|LUAI_DDEC
value|LUAI_FUNC
end_define

begin_define
define|#
directive|define
name|LUAI_DDEF
end_define

begin_comment
comment|/* empty */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_define
define|#
directive|define
name|LUAI_FUNC
value|extern
end_define

begin_define
define|#
directive|define
name|LUAI_DDEC
value|extern
end_define

begin_define
define|#
directive|define
name|LUAI_DDEF
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* @@ LUA_QL describes how error messages quote program elements. ** CHANGE it if you want a different appearance. */
end_comment

begin_define
define|#
directive|define
name|LUA_QL
parameter_list|(
name|x
parameter_list|)
value|"'" x "'"
end_define

begin_define
define|#
directive|define
name|LUA_QS
value|LUA_QL("%s")
end_define

begin_comment
comment|/* @@ LUA_IDSIZE gives the maximum size for the description of the source @* of a function in debug information. ** CHANGE it if you want a different size. */
end_comment

begin_define
define|#
directive|define
name|LUA_IDSIZE
value|60
end_define

begin_comment
comment|/* @@ luai_writestringerror defines how to print error messages. ** (A format string with one argument is enough for Lua...) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|luai_writestringerror
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
define|\
value|(zfs_dbgmsg((s), (p)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|luai_writestringerror
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
define|\
value|(fprintf(stderr, (s), (p)), fflush(stderr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ LUAI_MAXSHORTLEN is the maximum length for short strings, that is, ** strings that are internalized. (Cannot be smaller than reserved words ** or tags for metamethods, as these strings must be internalized; ** #("function") = 8, #("__newindex") = 10.) */
end_comment

begin_define
define|#
directive|define
name|LUAI_MAXSHORTLEN
value|40
end_define

begin_comment
comment|/* ** {================================================================== ** Compatibility with previous versions ** =================================================================== */
end_comment

begin_comment
comment|/* @@ LUA_COMPAT_ALL controls all compatibility options. ** You can define it to get all options, or change specific options ** to fit your specific needs. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_COMPAT_ALL
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_comment
comment|/* @@ LUA_COMPAT_UNPACK controls the presence of global 'unpack'. ** You can replace it with 'table.unpack'. */
end_comment

begin_define
define|#
directive|define
name|LUA_COMPAT_UNPACK
end_define

begin_comment
comment|/* @@ LUA_COMPAT_LOADERS controls the presence of table 'package.loaders'. ** You can replace it with 'package.searchers'. */
end_comment

begin_define
define|#
directive|define
name|LUA_COMPAT_LOADERS
end_define

begin_comment
comment|/* @@ macro 'lua_cpcall' emulates deprecated function lua_cpcall. ** You can call your C function directly (with light C functions). */
end_comment

begin_define
define|#
directive|define
name|lua_cpcall
parameter_list|(
name|L
parameter_list|,
name|f
parameter_list|,
name|u
parameter_list|)
define|\
value|(lua_pushcfunction(L, (f)), \ 	 lua_pushlightuserdata(L,(u)), \ 	 lua_pcall(L,1,0,0))
end_define

begin_comment
comment|/* @@ LUA_COMPAT_LOG10 defines the function 'log10' in the math library. ** You can rewrite 'log10(x)' as 'log(x, 10)'. */
end_comment

begin_define
define|#
directive|define
name|LUA_COMPAT_LOG10
end_define

begin_comment
comment|/* @@ LUA_COMPAT_LOADSTRING defines the function 'loadstring' in the base ** library. You can rewrite 'loadstring(s)' as 'load(s)'. */
end_comment

begin_define
define|#
directive|define
name|LUA_COMPAT_LOADSTRING
end_define

begin_comment
comment|/* @@ LUA_COMPAT_MAXN defines the function 'maxn' in the table library. */
end_comment

begin_define
define|#
directive|define
name|LUA_COMPAT_MAXN
end_define

begin_comment
comment|/* @@ The following macros supply trivial compatibility for some ** changes in the API. The macros themselves document how to ** change your code to avoid using them. */
end_comment

begin_define
define|#
directive|define
name|lua_strlen
parameter_list|(
name|L
parameter_list|,
name|i
parameter_list|)
value|lua_rawlen(L, (i))
end_define

begin_define
define|#
directive|define
name|lua_objlen
parameter_list|(
name|L
parameter_list|,
name|i
parameter_list|)
value|lua_rawlen(L, (i))
end_define

begin_define
define|#
directive|define
name|lua_equal
parameter_list|(
name|L
parameter_list|,
name|idx1
parameter_list|,
name|idx2
parameter_list|)
value|lua_compare(L,(idx1),(idx2),LUA_OPEQ)
end_define

begin_define
define|#
directive|define
name|lua_lessthan
parameter_list|(
name|L
parameter_list|,
name|idx1
parameter_list|,
name|idx2
parameter_list|)
value|lua_compare(L,(idx1),(idx2),LUA_OPLT)
end_define

begin_comment
comment|/* @@ LUA_COMPAT_MODULE controls compatibility with previous ** module functions 'module' (Lua) and 'luaL_register' (C). */
end_comment

begin_define
define|#
directive|define
name|LUA_COMPAT_MODULE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* }================================================================== */
end_comment

begin_comment
comment|/* @@ LUAI_BITSINT defines the number of bits in an int. ** CHANGE here if Lua cannot automatically detect the number of bits of ** your machine. Probably you do not need to change this. */
end_comment

begin_comment
comment|/* avoid overflows in comparison */
end_comment

begin_if
if|#
directive|if
name|INT_MAX
operator|-
literal|20
operator|<
literal|32760
end_if

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|LUAI_BITSINT
value|16
end_define

begin_elif
elif|#
directive|elif
name|INT_MAX
operator|>
literal|2147483640L
end_elif

begin_comment
comment|/* }{ */
end_comment

begin_comment
comment|/* int has at least 32 bits */
end_comment

begin_define
define|#
directive|define
name|LUAI_BITSINT
value|32
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_error
error|#
directive|error
literal|"you must define LUA_BITSINT with number of bits in an integer"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* @@ LUA_INT32 is a signed integer with exactly 32 bits. @@ LUAI_UMEM is an unsigned integer big enough to count the total @* memory used by Lua. @@ LUAI_MEM is a signed integer big enough to count the total memory @* used by Lua. ** CHANGE here if for some weird reason the default definitions are not ** good enough for your machine. Probably you do not need to change ** this. */
end_comment

begin_if
if|#
directive|if
name|LUAI_BITSINT
operator|>=
literal|32
end_if

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|LUA_INT32
value|int
end_define

begin_define
define|#
directive|define
name|LUAI_UMEM
value|size_t
end_define

begin_define
define|#
directive|define
name|LUAI_MEM
value|ptrdiff_t
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_comment
comment|/* 16-bit ints */
end_comment

begin_define
define|#
directive|define
name|LUA_INT32
value|long
end_define

begin_define
define|#
directive|define
name|LUAI_UMEM
value|unsigned long
end_define

begin_define
define|#
directive|define
name|LUAI_MEM
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* @@ LUAI_MAXSTACK limits the size of the Lua stack. ** CHANGE it if you need a different limit. This limit is arbitrary; ** its only purpose is to stop Lua from consuming unlimited stack ** space (and to reserve some numbers for pseudo-indices). */
end_comment

begin_if
if|#
directive|if
name|LUAI_BITSINT
operator|>=
literal|32
end_if

begin_define
define|#
directive|define
name|LUAI_MAXSTACK
value|1000000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LUAI_MAXSTACK
value|15000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* reserve some space for error handling */
end_comment

begin_define
define|#
directive|define
name|LUAI_FIRSTPSEUDOIDX
value|(-LUAI_MAXSTACK - 1000)
end_define

begin_comment
comment|/* @@ LUAL_BUFFERSIZE is the buffer size used by the lauxlib buffer system. ** CHANGE it if it uses too much C-stack space. */
end_comment

begin_define
define|#
directive|define
name|LUAL_BUFFERSIZE
value|1024
end_define

begin_comment
comment|/* ** {================================================================== @@ LUA_NUMBER is the type of numbers in Lua. ** CHANGE the following definitions only if you want to build Lua ** with a number type different from double. You may also need to ** change lua_number2int& lua_number2integer. ** =================================================================== */
end_comment

begin_define
define|#
directive|define
name|LUA_NUMBER
value|int64_t
end_define

begin_comment
comment|/* @@ LUAI_UACNUMBER is the result of an 'usual argument conversion' @* over a number. */
end_comment

begin_define
define|#
directive|define
name|LUAI_UACNUMBER
value|int64_t
end_define

begin_comment
comment|/* @@ LUA_NUMBER_SCAN is the format for reading numbers. @@ LUA_NUMBER_FMT is the format for writing numbers. @@ lua_number2str converts a number to a string. @@ LUAI_MAXNUMBER2STR is maximum size of previous conversion. */
end_comment

begin_define
define|#
directive|define
name|LUA_NUMBER_FMT
value|"%" PRId64
end_define

begin_define
define|#
directive|define
name|lua_number2str
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|lcompat_sprintf((s), LUA_NUMBER_FMT, (n))
end_define

begin_define
define|#
directive|define
name|LUAI_MAXNUMBER2STR
value|32
end_define

begin_comment
comment|/* 16 digits, sign, point, and \0 */
end_comment

begin_comment
comment|/* @@ l_mathop allows the addition of an 'l' or 'f' to all math operations */
end_comment

begin_define
define|#
directive|define
name|l_mathop
parameter_list|(
name|x
parameter_list|)
value|(x ## l)
end_define

begin_comment
comment|/* @@ lua_str2number converts a decimal numeric string to a number. @@ lua_strx2number converts an hexadecimal numeric string to a number. ** In C99, 'strtod' does both conversions. C89, however, has no function ** to convert floating hexadecimal strings to numbers. For these ** systems, you can leave 'lua_strx2number' undefined and Lua will ** provide its own implementation. */
end_comment

begin_define
define|#
directive|define
name|lua_str2number
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|lcompat_strtoll((s), (p))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_USE_STRTODHEX
argument_list|)
end_if

begin_define
define|#
directive|define
name|lua_strx2number
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|lcompat_strtoll((s), (p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ The luai_num* macros define the primitive operations over numbers. */
end_comment

begin_comment
comment|/* the following operations need the math library */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|lobject_c
argument_list|)
operator|||
name|defined
argument_list|(
name|lvm_c
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_nummod
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) % (b))
end_define

begin_define
define|#
directive|define
name|luai_numpow
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|(lcompat_pow((a),(b)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* these are quite standard operations */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_CORE
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_numadd
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)+(b))
end_define

begin_define
define|#
directive|define
name|luai_numsub
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)-(b))
end_define

begin_define
define|#
directive|define
name|luai_nummul
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)*(b))
end_define

begin_define
define|#
directive|define
name|luai_numdiv
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)/(b))
end_define

begin_define
define|#
directive|define
name|luai_numunm
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|)
value|(-(a))
end_define

begin_define
define|#
directive|define
name|luai_numeq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)==(b))
end_define

begin_define
define|#
directive|define
name|luai_numlt
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b))
end_define

begin_define
define|#
directive|define
name|luai_numle
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<=(b))
end_define

begin_define
define|#
directive|define
name|luai_numisnan
parameter_list|(
name|L
parameter_list|,
name|a
parameter_list|)
value|(!luai_numeq((a), (a)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ LUA_INTEGER is the integral type used by lua_pushinteger/lua_tointeger. ** CHANGE that if ptrdiff_t is not adequate on your machine. (On most ** machines, ptrdiff_t gives a good choice between int or long.) */
end_comment

begin_define
define|#
directive|define
name|LUA_INTEGER
value|ptrdiff_t
end_define

begin_comment
comment|/* @@ LUA_UNSIGNED is the integral type used by lua_pushunsigned/lua_tounsigned. ** It must have at least 32 bits. */
end_comment

begin_define
define|#
directive|define
name|LUA_UNSIGNED
value|uint64_t
end_define

begin_comment
comment|/* ** Some tricks with doubles */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_NUMBER_DOUBLE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LUA_ANSI
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_comment
comment|/* ** The next definitions activate some tricks to speed up the ** conversion from doubles to integer types, mainly to LUA_UNSIGNED. ** @@ LUA_MSASMTRICK uses Microsoft assembler to avoid clashes with a ** DirectX idiosyncrasy. ** @@ LUA_IEEE754TRICK uses a trick that should work on any machine ** using IEEE754 with a 32-bit integer type. ** @@ LUA_IEEELL extends the trick to LUA_INTEGER; should only be ** defined when LUA_INTEGER is a 32-bit integer. ** @@ LUA_IEEEENDIAN is the endianness of doubles in your machine ** (0 for little endian, 1 for big endian); if not defined, Lua will ** check it dynamically for LUA_IEEE754TRICK (but not for LUA_NANTRICK). ** @@ LUA_NANTRICK controls the use of a trick to pack all types into ** a single double value, using NaN values to represent non-number ** values. The trick only works on 32-bit machines (ints and pointers ** are 32-bit values) with numbers represented as IEEE 754-2008 doubles ** with conventional endianess (12345678 or 87654321), in CPUs that do ** not produce signaling NaN values (all NaNs are quiet). */
end_comment

begin_comment
comment|/* Microsoft compiler on a Pentium (32 bit) ? */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_WIN
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|_M_IX86
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|LUA_MSASMTRICK
end_define

begin_define
define|#
directive|define
name|LUA_IEEEENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|LUA_NANTRICK
end_define

begin_comment
comment|/* pentium 32 bits? */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__X86__
argument_list|)
end_elif

begin_comment
comment|/* }{ */
end_comment

begin_define
define|#
directive|define
name|LUA_IEEE754TRICK
end_define

begin_define
define|#
directive|define
name|LUA_IEEELL
end_define

begin_define
define|#
directive|define
name|LUA_IEEEENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|LUA_NANTRICK
end_define

begin_comment
comment|/* pentium 64 bits? */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64
argument_list|)
end_elif

begin_comment
comment|/* }{ */
end_comment

begin_define
define|#
directive|define
name|LUA_IEEE754TRICK
end_define

begin_define
define|#
directive|define
name|LUA_IEEEENDIAN
value|0
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__POWERPC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
end_elif

begin_comment
comment|/* }{ */
end_comment

begin_define
define|#
directive|define
name|LUA_IEEE754TRICK
end_define

begin_define
define|#
directive|define
name|LUA_IEEEENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_comment
comment|/* assume IEEE754 and a 32-bit integer type */
end_comment

begin_define
define|#
directive|define
name|LUA_IEEE754TRICK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* }================================================================== */
end_comment

begin_comment
comment|/* =================================================================== */
end_comment

begin_comment
comment|/* ** Local configuration. You can use this space to add your redefinitions ** without modifying the main part of the file. */
end_comment

begin_define
define|#
directive|define
name|getlocaledecpoint
parameter_list|()
value|('.')
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|(((x)< 0) ? -(x) : (x))
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UCHAR_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|UCHAR_MAX
value|(0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

