begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Support.h - Support C Interface --------------------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file defines the C interface to the LLVM support library.             *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_SUPPORT_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

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
comment|/**  * This function permanently loads the dynamic library at the given path.  * It is safe to call this function multiple times for the same library.  *  * @see sys::DynamicLibrary::LoadLibraryPermanently()   */
name|LLVMBool
name|LLVMLoadLibraryPermanently
parameter_list|(
specifier|const
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
comment|/**  * This function parses the given arguments using the LLVM command line parser.  * Note that the only stable thing about this function is its signature; you  * cannot rely on any particular set of command line arguments being interpreted  * the same way across LLVM versions.  *  * @see llvm::cl::ParseCommandLineOptions()  */
name|void
name|LLVMParseCommandLineOptions
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|Overview
parameter_list|)
function_decl|;
comment|/**  * This function will search through all previously loaded dynamic  * libraries for the symbol \p symbolName. If it is found, the address of  * that symbol is returned. If not, null is returned.  *  * @see sys::DynamicLibrary::SearchForAddressOfSymbol()  */
name|void
modifier|*
name|LLVMSearchForAddressOfSymbol
parameter_list|(
specifier|const
name|char
modifier|*
name|symbolName
parameter_list|)
function_decl|;
comment|/**  * This functions permanently adds the symbol \p symbolName with the  * value \p symbolValue.  These symbols are searched before any  * libraries.  *  * @see sys::DynamicLibrary::AddSymbol()  */
name|void
name|LLVMAddSymbol
parameter_list|(
specifier|const
name|char
modifier|*
name|symbolName
parameter_list|,
name|void
modifier|*
name|symbolValue
parameter_list|)
function_decl|;
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

