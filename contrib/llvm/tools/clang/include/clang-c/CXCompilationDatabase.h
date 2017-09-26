begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- clang-c/CXCompilationDatabase.h - Compilation database  ---*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides a public interface to use CompilationDatabase without *| |* the full Clang C++ API.                                                    *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_C_CXCOMPILATIONDATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_C_CXCOMPILATIONDATABASE_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Platform.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/CXString.h"
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
comment|/** \defgroup COMPILATIONDB CompilationDatabase functions  * \ingroup CINDEX  *  * @{  */
comment|/**  * A compilation database holds all information used to compile files in a  * project. For each file in the database, it can be queried for the working  * directory or the command line used for the compiler invocation.  *  * Must be freed by \c clang_CompilationDatabase_dispose  */
typedef|typedef
name|void
modifier|*
name|CXCompilationDatabase
typedef|;
comment|/**  * \brief Contains the results of a search in the compilation database  *  * When searching for the compile command for a file, the compilation db can  * return several commands, as the file may have been compiled with  * different options in different places of the project. This choice of compile  * commands is wrapped in this opaque data structure. It must be freed by  * \c clang_CompileCommands_dispose.  */
typedef|typedef
name|void
modifier|*
name|CXCompileCommands
typedef|;
comment|/**  * \brief Represents the command line invocation to compile a specific file.  */
typedef|typedef
name|void
modifier|*
name|CXCompileCommand
typedef|;
comment|/**  * \brief Error codes for Compilation Database  */
typedef|typedef
enum|enum
block|{
comment|/*    * \brief No error occurred    */
name|CXCompilationDatabase_NoError
init|=
literal|0
block|,
comment|/*    * \brief Database can not be loaded    */
name|CXCompilationDatabase_CanNotLoadDatabase
init|=
literal|1
block|}
name|CXCompilationDatabase_Error
typedef|;
comment|/**  * \brief Creates a compilation database from the database found in directory  * buildDir. For example, CMake can output a compile_commands.json which can  * be used to build the database.  *  * It must be freed by \c clang_CompilationDatabase_dispose.  */
name|CINDEX_LINKAGE
name|CXCompilationDatabase
name|clang_CompilationDatabase_fromDirectory
parameter_list|(
specifier|const
name|char
modifier|*
name|BuildDir
parameter_list|,
name|CXCompilationDatabase_Error
modifier|*
name|ErrorCode
parameter_list|)
function_decl|;
comment|/**  * \brief Free the given compilation database  */
name|CINDEX_LINKAGE
name|void
name|clang_CompilationDatabase_dispose
parameter_list|(
name|CXCompilationDatabase
parameter_list|)
function_decl|;
comment|/**  * \brief Find the compile commands used for a file. The compile commands  * must be freed by \c clang_CompileCommands_dispose.  */
name|CINDEX_LINKAGE
name|CXCompileCommands
name|clang_CompilationDatabase_getCompileCommands
parameter_list|(
name|CXCompilationDatabase
parameter_list|,
specifier|const
name|char
modifier|*
name|CompleteFileName
parameter_list|)
function_decl|;
comment|/**  * \brief Get all the compile commands in the given compilation database.  */
name|CINDEX_LINKAGE
name|CXCompileCommands
name|clang_CompilationDatabase_getAllCompileCommands
parameter_list|(
name|CXCompilationDatabase
parameter_list|)
function_decl|;
comment|/**  * \brief Free the given CompileCommands  */
name|CINDEX_LINKAGE
name|void
name|clang_CompileCommands_dispose
parameter_list|(
name|CXCompileCommands
parameter_list|)
function_decl|;
comment|/**  * \brief Get the number of CompileCommand we have for a file  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CompileCommands_getSize
parameter_list|(
name|CXCompileCommands
parameter_list|)
function_decl|;
comment|/**  * \brief Get the I'th CompileCommand for a file  *  * Note : 0<= i< clang_CompileCommands_getSize(CXCompileCommands)  */
name|CINDEX_LINKAGE
name|CXCompileCommand
name|clang_CompileCommands_getCommand
parameter_list|(
name|CXCompileCommands
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * \brief Get the working directory where the CompileCommand was executed from  */
name|CINDEX_LINKAGE
name|CXString
name|clang_CompileCommand_getDirectory
parameter_list|(
name|CXCompileCommand
parameter_list|)
function_decl|;
comment|/**  * \brief Get the filename associated with the CompileCommand.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_CompileCommand_getFilename
parameter_list|(
name|CXCompileCommand
parameter_list|)
function_decl|;
comment|/**  * \brief Get the number of arguments in the compiler invocation.  *  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CompileCommand_getNumArgs
parameter_list|(
name|CXCompileCommand
parameter_list|)
function_decl|;
comment|/**  * \brief Get the I'th argument value in the compiler invocations  *  * Invariant :  *  - argument 0 is the compiler executable  */
name|CINDEX_LINKAGE
name|CXString
name|clang_CompileCommand_getArg
parameter_list|(
name|CXCompileCommand
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * \brief Get the number of source mappings for the compiler invocation.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CompileCommand_getNumMappedSources
parameter_list|(
name|CXCompileCommand
parameter_list|)
function_decl|;
comment|/**  * \brief Get the I'th mapped source path for the compiler invocation.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_CompileCommand_getMappedSourcePath
parameter_list|(
name|CXCompileCommand
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * \brief Get the I'th mapped source content for the compiler invocation.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_CompileCommand_getMappedSourceContent
parameter_list|(
name|CXCompileCommand
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * @}  */
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

