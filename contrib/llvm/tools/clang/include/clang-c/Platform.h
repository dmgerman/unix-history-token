begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- clang-c/Platform.h - C Index platform decls   -------------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides platform specific macros (dllimport, deprecated, ...) *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_C_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_C_PLATFORM_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* MSVC DLL import/export. */
ifdef|#
directive|ifdef
name|_MSC_VER
ifdef|#
directive|ifdef
name|_CINDEX_LIB_
define|#
directive|define
name|CINDEX_LINKAGE
value|__declspec(dllexport)
else|#
directive|else
define|#
directive|define
name|CINDEX_LINKAGE
value|__declspec(dllimport)
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|CINDEX_LINKAGE
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__GNUC__
define|#
directive|define
name|CINDEX_DEPRECATED
value|__attribute__((deprecated))
else|#
directive|else
ifdef|#
directive|ifdef
name|_MSC_VER
define|#
directive|define
name|CINDEX_DEPRECATED
value|__declspec(deprecated)
else|#
directive|else
define|#
directive|define
name|CINDEX_DEPRECATED
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

