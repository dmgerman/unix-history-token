begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ProgramInfo.h - Information about the loaded program -----*- C++ -*-===//
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
comment|// This file defines various pieces of information about the currently loaded
end_comment

begin_comment
comment|// program.  One instance of this object is created every time a program is
end_comment

begin_comment
comment|// loaded, and destroyed every time it is unloaded.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The various pieces of information gathered about the source program are all
end_comment

begin_comment
comment|// designed to be extended by various SourceLanguage implementations.  This
end_comment

begin_comment
comment|// allows source languages to keep any extended information that they support in
end_comment

begin_comment
comment|// the derived class portions of the class.
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
name|LLVM_DEBUGGER_PROGRAMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGGER_PROGRAMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/TimeValue.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|SourceFile
decl_stmt|;
name|class
name|SourceLanguage
decl_stmt|;
name|class
name|ProgramInfo
decl_stmt|;
comment|/// SourceLanguageCache - SourceLanguage implementations are allowed to cache
comment|/// stuff in the ProgramInfo object.  The only requirement we have on these
comment|/// instances is that they are destroyable.
struct|struct
name|SourceLanguageCache
block|{
name|virtual
operator|~
name|SourceLanguageCache
argument_list|()
block|{}
block|}
struct|;
comment|/// SourceFileInfo - One instance of this structure is created for each
comment|/// source file in the program.
comment|///
name|class
name|SourceFileInfo
block|{
comment|/// BaseName - The filename of the source file.
name|std
operator|::
name|string
name|BaseName
expr_stmt|;
comment|/// Directory - The working directory of this source file when it was
comment|/// compiled.
name|std
operator|::
name|string
name|Directory
expr_stmt|;
comment|/// Version - The version of the LLVM debug information that this file was
comment|/// compiled with.
name|unsigned
name|Version
decl_stmt|;
comment|/// Language - The source language that the file was compiled with.  This
comment|/// pointer is never null.
comment|///
specifier|const
name|SourceLanguage
modifier|*
name|Language
decl_stmt|;
comment|/// Descriptor - The LLVM Global Variable which describes the source file.
comment|///
specifier|const
name|GlobalVariable
modifier|*
name|Descriptor
decl_stmt|;
comment|/// SourceText - The body of this source file, or null if it has not yet
comment|/// been loaded.
name|mutable
name|SourceFile
modifier|*
name|SourceText
decl_stmt|;
name|public
label|:
name|SourceFileInfo
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|Desc
argument_list|,
specifier|const
name|SourceLanguage
operator|&
name|Lang
argument_list|)
expr_stmt|;
operator|~
name|SourceFileInfo
argument_list|()
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getBaseName
argument_list|()
specifier|const
block|{
return|return
name|BaseName
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getDirectory
argument_list|()
specifier|const
block|{
return|return
name|Directory
return|;
block|}
name|unsigned
name|getDebugVersion
argument_list|()
specifier|const
block|{
return|return
name|Version
return|;
block|}
specifier|const
name|GlobalVariable
operator|*
name|getDescriptor
argument_list|()
specifier|const
block|{
return|return
name|Descriptor
return|;
block|}
name|SourceFile
operator|&
name|getSourceText
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|SourceLanguage
operator|&
name|getLanguage
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Language
return|;
block|}
block|}
empty_stmt|;
comment|/// SourceFunctionInfo - An instance of this class is used to represent each
comment|/// source function in the program.
comment|///
name|class
name|SourceFunctionInfo
block|{
comment|/// Name - This contains an abstract name that is potentially useful to the
comment|/// end-user.  If there is no explicit support for the current language,
comment|/// then this string is used to identify the function.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// Descriptor - The descriptor for this function.
comment|///
specifier|const
name|GlobalVariable
modifier|*
name|Descriptor
decl_stmt|;
comment|/// SourceFile - The file that this function is defined in.
comment|///
specifier|const
name|SourceFileInfo
modifier|*
name|SourceFile
decl_stmt|;
comment|/// LineNo, ColNo - The location of the first stop-point in the function.
comment|/// These are computed on demand.
name|mutable
name|unsigned
name|LineNo
decl_stmt|,
name|ColNo
decl_stmt|;
name|public
label|:
name|SourceFunctionInfo
argument_list|(
name|ProgramInfo
operator|&
name|PI
argument_list|,
specifier|const
name|GlobalVariable
operator|*
name|Desc
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|SourceFunctionInfo
argument_list|()
block|{}
comment|/// getSymbolicName - Return a human-readable symbolic name to identify the
comment|/// function (for example, in stack traces).
name|virtual
name|std
operator|::
name|string
name|getSymbolicName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getDescriptor - This returns the descriptor for the function.
comment|///
specifier|const
name|GlobalVariable
operator|*
name|getDescriptor
argument_list|()
specifier|const
block|{
return|return
name|Descriptor
return|;
block|}
comment|/// getSourceFile - This returns the source file that defines the function.
comment|///
specifier|const
name|SourceFileInfo
operator|&
name|getSourceFile
argument_list|()
specifier|const
block|{
return|return
operator|*
name|SourceFile
return|;
block|}
comment|/// getSourceLocation - This method returns the location of the first
comment|/// stopping point in the function.  If the body of the function cannot be
comment|/// found, this returns zeros for both values.
name|void
name|getSourceLocation
argument_list|(
name|unsigned
operator|&
name|LineNo
argument_list|,
name|unsigned
operator|&
name|ColNo
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// ProgramInfo - This object contains information about the loaded program.
comment|/// When a new program is loaded, an instance of this class is created.  When
comment|/// the program is unloaded, the instance is destroyed.  This object basically
comment|/// manages the lazy computation of information useful for the debugger.
name|class
name|ProgramInfo
block|{
name|Module
modifier|*
name|M
decl_stmt|;
comment|/// ProgramTimeStamp - This is the timestamp of the executable file that we
comment|/// currently have loaded into the debugger.
name|sys
operator|::
name|TimeValue
name|ProgramTimeStamp
expr_stmt|;
comment|/// SourceFiles - This map is used to transform source file descriptors into
comment|/// their corresponding SourceFileInfo objects.  This mapping owns the
comment|/// memory for the SourceFileInfo objects.
comment|///
name|bool
name|SourceFilesIsComplete
decl_stmt|;
name|std
operator|::
name|map
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|,
name|SourceFileInfo
operator|*
operator|>
name|SourceFiles
expr_stmt|;
comment|/// SourceFileIndex - Mapping from source file basenames to the information
comment|/// about the file.  Note that there can be filename collisions, so this is
comment|/// a multimap.  This map is populated incrementally as the user interacts
comment|/// with the program, through the getSourceFileFromDesc method.  If ALL of
comment|/// the source files are needed, the getSourceFiles() method scans the
comment|/// entire program looking for them.
comment|///
name|std
operator|::
name|multimap
operator|<
name|std
operator|::
name|string
operator|,
name|SourceFileInfo
operator|*
operator|>
name|SourceFileIndex
expr_stmt|;
comment|/// SourceFunctions - This map contains entries functions in the source
comment|/// program.  If SourceFunctionsIsComplete is true, then this is ALL of the
comment|/// functions in the program are in this map.
name|bool
name|SourceFunctionsIsComplete
decl_stmt|;
name|std
operator|::
name|map
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|,
name|SourceFunctionInfo
operator|*
operator|>
name|SourceFunctions
expr_stmt|;
comment|/// LanguageCaches - Each source language is permitted to keep a per-program
comment|/// cache of information specific to whatever it needs.  This vector is
comment|/// effectively a small map from the languages that are active in the
comment|/// program to their caches.  This can be accessed by the language by the
comment|/// "getLanguageCache" method.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|SourceLanguage
operator|*
operator|,
name|SourceLanguageCache
operator|*
operator|>
expr|>
name|LanguageCaches
expr_stmt|;
name|public
label|:
name|ProgramInfo
argument_list|(
name|Module
operator|*
name|m
argument_list|)
expr_stmt|;
operator|~
name|ProgramInfo
argument_list|()
expr_stmt|;
comment|/// getProgramTimeStamp - Return the time-stamp of the program when it was
comment|/// loaded.
name|sys
operator|::
name|TimeValue
name|getProgramTimeStamp
argument_list|()
specifier|const
block|{
return|return
name|ProgramTimeStamp
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Interfaces to the source code files that make up the program.
comment|//
comment|/// getSourceFile - Return source file information for the specified source
comment|/// file descriptor object, adding it to the collection as needed.  This
comment|/// method always succeeds (is unambiguous), and is always efficient.
comment|///
specifier|const
name|SourceFileInfo
modifier|&
name|getSourceFile
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|Desc
parameter_list|)
function_decl|;
comment|/// getSourceFile - Look up the file with the specified name.  If there is
comment|/// more than one match for the specified filename, prompt the user to pick
comment|/// one.  If there is no source file that matches the specified name, throw
comment|/// an exception indicating that we can't find the file.  Otherwise, return
comment|/// the file information for that file.
comment|///
comment|/// If the source file hasn't been discovered yet in the program, this
comment|/// method might have to index the whole program by calling the
comment|/// getSourceFiles() method.
comment|///
specifier|const
name|SourceFileInfo
modifier|&
name|getSourceFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
decl_stmt|;
comment|/// getSourceFiles - Index all of the source files in the program and return
comment|/// them.  This information is lazily computed the first time that it is
comment|/// requested.  Since this information can take a long time to compute, the
comment|/// user is given a chance to cancel it.  If this occurs, an exception is
comment|/// thrown.
specifier|const
name|std
operator|::
name|map
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|,
name|SourceFileInfo
operator|*
operator|>
operator|&
name|getSourceFiles
argument_list|(
argument|bool RequiresCompleteMap = true
argument_list|)
expr_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Interfaces to the functions that make up the program.
comment|//
comment|/// getFunction - Return source function information for the specified
comment|/// function descriptor object, adding it to the collection as needed.  This
comment|/// method always succeeds (is unambiguous), and is always efficient.
comment|///
specifier|const
name|SourceFunctionInfo
modifier|&
name|getFunction
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|Desc
parameter_list|)
function_decl|;
comment|/// getSourceFunctions - Index all of the functions in the program and
comment|/// return them.  This information is lazily computed the first time that it
comment|/// is requested.  Since this information can take a long time to compute,
comment|/// the user is given a chance to cancel it.  If this occurs, an exception
comment|/// is thrown.
specifier|const
name|std
operator|::
name|map
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|,
name|SourceFunctionInfo
operator|*
operator|>
operator|&
name|getSourceFunctions
argument_list|(
argument|bool RequiresCompleteMap = true
argument_list|)
expr_stmt|;
comment|/// addSourceFunctionsRead - Return true if the source functions map is
comment|/// complete: that is, all functions in the program have been read in.
name|bool
name|allSourceFunctionsRead
argument_list|()
specifier|const
block|{
return|return
name|SourceFunctionsIsComplete
return|;
block|}
comment|/// getLanguageCache - This method is used to build per-program caches of
comment|/// information, such as the functions or types visible to the program.
comment|/// This can be used by SourceLanguage implementations because it requires
comment|/// an accessible [sl]::CacheType typedef, where [sl] is the C++ type of the
comment|/// source-language subclass.
name|template
operator|<
name|typename
name|SL
operator|>
name|typename
name|SL
operator|::
name|CacheType
operator|&
name|getLanguageCache
argument_list|(
argument|const SL *L
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|LanguageCaches
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|LanguageCaches
index|[
name|i
index|]
operator|.
name|first
operator|==
name|L
condition|)
return|return
operator|*
operator|(
name|typename
name|SL
operator|::
name|CacheType
operator|*
operator|)
name|LanguageCaches
index|[
name|i
index|]
operator|.
name|second
return|;
name|typename
name|SL
operator|::
name|CacheType
operator|*
name|NewCache
operator|=
name|L
operator|->
name|createSourceLanguageCache
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
name|LanguageCaches
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|L
argument_list|,
name|NewCache
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|NewCache
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

