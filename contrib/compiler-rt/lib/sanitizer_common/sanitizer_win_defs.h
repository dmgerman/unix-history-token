begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_win_defs.h ------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Common definitions for Windows-specific code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_WIN_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_WIN_DEFS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_WINDOWS
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|WINAPI
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_M_IX86
end_ifdef

begin_define
define|#
directive|define
name|WINAPI
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WINAPI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIN_SYM_PREFIX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WIN_SYM_PREFIX
value|"_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Intermediate macro to ensure the parameter is expanded before stringified.
end_comment

begin_define
define|#
directive|define
name|STRINGIFY_
parameter_list|(
name|A
parameter_list|)
value|#A
end_define

begin_define
define|#
directive|define
name|STRINGIFY
parameter_list|(
name|A
parameter_list|)
value|STRINGIFY_(A)
end_define

begin_comment
comment|// ----------------- A workaround for the absence of weak symbols --------------
end_comment

begin_comment
comment|// We don't have a direct equivalent of weak symbols when using MSVC, but we can
end_comment

begin_comment
comment|// use the /alternatename directive to tell the linker to default a specific
end_comment

begin_comment
comment|// symbol to a specific value.
end_comment

begin_comment
comment|// Take into account that this is a pragma directive for the linker, so it will
end_comment

begin_comment
comment|// be ignored by the compiler and the function will be marked as UNDEF in the
end_comment

begin_comment
comment|// symbol table of the resulting object file. The linker won't find the default
end_comment

begin_comment
comment|// implementation until it links with that object file.
end_comment

begin_comment
comment|// So, suppose we provide a default implementation "fundef" for "fun", and this
end_comment

begin_comment
comment|// is compiled into the object file "test.obj" including the pragma directive.
end_comment

begin_comment
comment|// If we have some code with references to "fun" and we link that code with
end_comment

begin_comment
comment|// "test.obj", it will work because the linker always link object files.
end_comment

begin_comment
comment|// But, if "test.obj" is included in a static library, like "test.lib", then the
end_comment

begin_comment
comment|// liker will only link to "test.obj" if necessary. If we only included the
end_comment

begin_comment
comment|// definition of "fun", it won't link to "test.obj" (from test.lib) because
end_comment

begin_comment
comment|// "fun" appears as UNDEF, so it doesn't resolve the symbol "fun", and will
end_comment

begin_comment
comment|// result in a link error (the linker doesn't find the pragma directive).
end_comment

begin_comment
comment|// So, a workaround is to force linkage with the modules that include weak
end_comment

begin_comment
comment|// definitions, with the following macro: WIN_FORCE_LINK()
end_comment

begin_define
define|#
directive|define
name|WIN_WEAK_ALIAS
parameter_list|(
name|Name
parameter_list|,
name|Default
parameter_list|)
define|\
value|__pragma(comment(linker, "/alternatename:" WIN_SYM_PREFIX STRINGIFY(Name) "="\                                              WIN_SYM_PREFIX STRINGIFY(Default)))
end_define

begin_define
define|#
directive|define
name|WIN_FORCE_LINK
parameter_list|(
name|Name
parameter_list|)
define|\
value|__pragma(comment(linker, "/include:" WIN_SYM_PREFIX STRINGIFY(Name)))
end_define

begin_define
define|#
directive|define
name|WIN_EXPORT
parameter_list|(
name|ExportedName
parameter_list|,
name|Name
parameter_list|)
define|\
value|__pragma(comment(linker, "/export:" WIN_SYM_PREFIX STRINGIFY(ExportedName)   \                                   "=" WIN_SYM_PREFIX STRINGIFY(Name)))
end_define

begin_comment
comment|// We cannot define weak functions on Windows, but we can use WIN_WEAK_ALIAS()
end_comment

begin_comment
comment|// which defines an alias to a default implementation, and only works when
end_comment

begin_comment
comment|// linking statically.
end_comment

begin_comment
comment|// So, to define a weak function "fun", we define a default implementation with
end_comment

begin_comment
comment|// a different name "fun__def" and we create a "weak alias" fun = fun__def.
end_comment

begin_comment
comment|// Then, users can override it just defining "fun".
end_comment

begin_comment
comment|// We impose "extern "C"" because otherwise WIN_WEAK_ALIAS() will fail because
end_comment

begin_comment
comment|// of name mangling.
end_comment

begin_comment
comment|// Dummy name for default implementation of weak function.
end_comment

begin_define
define|#
directive|define
name|WEAK_DEFAULT_NAME
parameter_list|(
name|Name
parameter_list|)
value|Name##__def
end_define

begin_comment
comment|// Name for exported implementation of weak function.
end_comment

begin_define
define|#
directive|define
name|WEAK_EXPORT_NAME
parameter_list|(
name|Name
parameter_list|)
value|Name##__dll
end_define

begin_comment
comment|// Use this macro when you need to define and export a weak function from a
end_comment

begin_comment
comment|// library. For example:
end_comment

begin_comment
comment|//   WIN_WEAK_EXPORT_DEF(bool, compare, int a, int b) { return a> b; }
end_comment

begin_define
define|#
directive|define
name|WIN_WEAK_EXPORT_DEF
parameter_list|(
name|ReturnType
parameter_list|,
name|Name
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WIN_WEAK_ALIAS(Name, WEAK_DEFAULT_NAME(Name))                                \   WIN_EXPORT(WEAK_EXPORT_NAME(Name), Name)                                     \   extern "C" ReturnType Name(__VA_ARGS__);                                     \   extern "C" ReturnType WEAK_DEFAULT_NAME(Name)(__VA_ARGS__)
end_define

begin_comment
comment|// Use this macro when you need to import a weak function from a library. It
end_comment

begin_comment
comment|// defines a weak alias to the imported function from the dll. For example:
end_comment

begin_comment
comment|//   WIN_WEAK_IMPORT_DEF(compare)
end_comment

begin_define
define|#
directive|define
name|WIN_WEAK_IMPORT_DEF
parameter_list|(
name|Name
parameter_list|)
define|\
value|WIN_WEAK_ALIAS(Name, WEAK_EXPORT_NAME(Name))
end_define

begin_comment
comment|// So, for Windows we provide something similar to weak symbols in Linux, with
end_comment

begin_comment
comment|// some differences:
end_comment

begin_comment
comment|// + A default implementation must always be provided.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// + When linking statically it works quite similarly. For example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // libExample.cc
end_comment

begin_comment
comment|//   WIN_WEAK_EXPORT_DEF(bool, compare, int a, int b) { return a> b; }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // client.cc
end_comment

begin_comment
comment|//   // We can use the default implementation from the library:
end_comment

begin_comment
comment|//   compare(1, 2);
end_comment

begin_comment
comment|//   // Or we can override it:
end_comment

begin_comment
comment|//   extern "C" bool compare (int a, int b) { return a>= b; }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  And it will work fine. If we don't override the function, we need to ensure
end_comment

begin_comment
comment|//  that the linker includes the object file with the default implementation.
end_comment

begin_comment
comment|//  We can do so with the linker option "-wholearchive:".
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// + When linking dynamically with a library (dll), weak functions are exported
end_comment

begin_comment
comment|//  with "__dll" suffix. Clients can use the macro WIN_WEAK_IMPORT_DEF(fun)
end_comment

begin_comment
comment|//  which defines a "weak alias" fun = fun__dll.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // libExample.cc
end_comment

begin_comment
comment|//   WIN_WEAK_EXPORT_DEF(bool, compare, int a, int b) { return a> b; }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // client.cc
end_comment

begin_comment
comment|//   WIN_WEAK_IMPORT_DEF(compare)
end_comment

begin_comment
comment|//   // We can use the default implementation from the library:
end_comment

begin_comment
comment|//   compare(1, 2);
end_comment

begin_comment
comment|//   // Or we can override it:
end_comment

begin_comment
comment|//   extern "C" bool compare (int a, int b) { return a>= b; }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  But if we override the function, the dlls don't have access to it (which
end_comment

begin_comment
comment|//  is different in linux). If that is desired, the strong definition must be
end_comment

begin_comment
comment|//  exported and interception can be used from the rest of the dlls.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // libExample.cc
end_comment

begin_comment
comment|//   WIN_WEAK_EXPORT_DEF(bool, compare, int a, int b) { return a> b; }
end_comment

begin_comment
comment|//   // When initialized, check if the main executable defined "compare".
end_comment

begin_comment
comment|//   int libExample_init() {
end_comment

begin_comment
comment|//     uptr fnptr = __interception::InternalGetProcAddress(
end_comment

begin_comment
comment|//         (void *)GetModuleHandleA(0), "compare");
end_comment

begin_comment
comment|//     if (fnptr&& !__interception::OverrideFunction((uptr)compare, fnptr, 0))
end_comment

begin_comment
comment|//       abort();
end_comment

begin_comment
comment|//     return 0;
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // client.cc
end_comment

begin_comment
comment|//   WIN_WEAK_IMPORT_DEF(compare)
end_comment

begin_comment
comment|//   // We override and export compare:
end_comment

begin_comment
comment|//   extern "C" __declspec(dllexport) bool compare (int a, int b) {
end_comment

begin_comment
comment|//     return a>= b;
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_WINDOWS
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_WIN_DEFS_H
end_comment

end_unit

