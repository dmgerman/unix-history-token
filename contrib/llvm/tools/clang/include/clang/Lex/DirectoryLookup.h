begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DirectoryLookup.h - Info for searching for headers -----*- C++ -*-===//
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
comment|// This file defines the DirectoryLookup interface.
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
name|LLVM_CLANG_LEX_DIRECTORYLOOKUP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_DIRECTORYLOOKUP_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|HeaderMap
decl_stmt|;
name|class
name|DirectoryEntry
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
comment|/// DirectoryLookup - This class represents one entry in the search list that
comment|/// specifies the search order for directories in #include directives.  It
comment|/// represents either a directory, a framework, or a headermap.
comment|///
name|class
name|DirectoryLookup
block|{
name|public
label|:
enum|enum
name|LookupType_t
block|{
name|LT_NormalDir
block|,
name|LT_Framework
block|,
name|LT_HeaderMap
block|}
enum|;
name|private
label|:
union|union
block|{
comment|// This union is discriminated by isHeaderMap.
comment|/// Dir - This is the actual directory that we're referring to for a normal
comment|/// directory or a framework.
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
decl_stmt|;
comment|/// Map - This is the HeaderMap if this is a headermap lookup.
comment|///
specifier|const
name|HeaderMap
modifier|*
name|Map
decl_stmt|;
block|}
name|u
union|;
comment|/// DirCharacteristic - The type of directory this is: this is an instance of
comment|/// SrcMgr::CharacteristicKind.
name|unsigned
name|DirCharacteristic
range|:
literal|2
decl_stmt|;
comment|/// UserSupplied - True if this is a user-supplied directory.
comment|///
name|bool
name|UserSupplied
range|:
literal|1
decl_stmt|;
comment|/// LookupType - This indicates whether this DirectoryLookup object is a
comment|/// normal directory, a framework, or a headermap.
name|unsigned
name|LookupType
range|:
literal|2
decl_stmt|;
name|public
label|:
comment|/// DirectoryLookup ctor - Note that this ctor *does not take ownership* of
comment|/// 'dir'.
name|DirectoryLookup
argument_list|(
argument|const DirectoryEntry *dir
argument_list|,
argument|SrcMgr::CharacteristicKind DT
argument_list|,
argument|bool isUser
argument_list|,
argument|bool isFramework
argument_list|)
block|:
name|DirCharacteristic
argument_list|(
name|DT
argument_list|)
operator|,
name|UserSupplied
argument_list|(
name|isUser
argument_list|)
operator|,
name|LookupType
argument_list|(
argument|isFramework ? LT_Framework : LT_NormalDir
argument_list|)
block|{
name|u
operator|.
name|Dir
operator|=
name|dir
block|;   }
comment|/// DirectoryLookup ctor - Note that this ctor *does not take ownership* of
comment|/// 'map'.
name|DirectoryLookup
argument_list|(
argument|const HeaderMap *map
argument_list|,
argument|SrcMgr::CharacteristicKind DT
argument_list|,
argument|bool isUser
argument_list|)
operator|:
name|DirCharacteristic
argument_list|(
name|DT
argument_list|)
operator|,
name|UserSupplied
argument_list|(
name|isUser
argument_list|)
operator|,
name|LookupType
argument_list|(
argument|LT_HeaderMap
argument_list|)
block|{
name|u
operator|.
name|Map
operator|=
name|map
block|;   }
comment|/// getLookupType - Return the kind of directory lookup that this is: either a
comment|/// normal directory, a framework path, or a HeaderMap.
name|LookupType_t
name|getLookupType
argument_list|()
specifier|const
block|{
return|return
operator|(
name|LookupType_t
operator|)
name|LookupType
return|;
block|}
comment|/// getName - Return the directory or filename corresponding to this lookup
comment|/// object.
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getDir - Return the directory that this entry refers to.
comment|///
specifier|const
name|DirectoryEntry
operator|*
name|getDir
argument_list|()
specifier|const
block|{
return|return
name|isNormalDir
argument_list|()
operator|?
name|u
operator|.
name|Dir
operator|:
literal|0
return|;
block|}
comment|/// getFrameworkDir - Return the directory that this framework refers to.
comment|///
specifier|const
name|DirectoryEntry
operator|*
name|getFrameworkDir
argument_list|()
specifier|const
block|{
return|return
name|isFramework
argument_list|()
operator|?
name|u
operator|.
name|Dir
operator|:
literal|0
return|;
block|}
comment|/// getHeaderMap - Return the directory that this entry refers to.
comment|///
specifier|const
name|HeaderMap
operator|*
name|getHeaderMap
argument_list|()
specifier|const
block|{
return|return
name|isHeaderMap
argument_list|()
operator|?
name|u
operator|.
name|Map
operator|:
literal|0
return|;
block|}
comment|/// isNormalDir - Return true if this is a normal directory, not a header map.
name|bool
name|isNormalDir
argument_list|()
specifier|const
block|{
return|return
name|getLookupType
argument_list|()
operator|==
name|LT_NormalDir
return|;
block|}
comment|/// isFramework - True if this is a framework directory.
comment|///
name|bool
name|isFramework
argument_list|()
specifier|const
block|{
return|return
name|getLookupType
argument_list|()
operator|==
name|LT_Framework
return|;
block|}
comment|/// isHeaderMap - Return true if this is a header map, not a normal directory.
name|bool
name|isHeaderMap
argument_list|()
specifier|const
block|{
return|return
name|getLookupType
argument_list|()
operator|==
name|LT_HeaderMap
return|;
block|}
comment|/// DirCharacteristic - The type of directory this is, one of the DirType enum
comment|/// values.
name|SrcMgr
operator|::
name|CharacteristicKind
name|getDirCharacteristic
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SrcMgr
operator|::
name|CharacteristicKind
operator|)
name|DirCharacteristic
return|;
block|}
comment|/// isUserSupplied - True if this is a user-supplied directory.
comment|///
name|bool
name|isUserSupplied
argument_list|()
specifier|const
block|{
return|return
name|UserSupplied
return|;
block|}
comment|/// LookupFile - Lookup the specified file in this search path, returning it
comment|/// if it exists or returning null if not.
specifier|const
name|FileEntry
modifier|*
name|LookupFile
argument_list|(
name|llvm
operator|::
name|StringRef
name|Filename
argument_list|,
name|HeaderSearch
operator|&
name|HS
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|const
name|FileEntry
modifier|*
name|DoFrameworkLookup
argument_list|(
name|llvm
operator|::
name|StringRef
name|Filename
argument_list|,
name|HeaderSearch
operator|&
name|HS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

