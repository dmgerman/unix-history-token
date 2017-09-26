begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Distro.h - Linux distribution detection support --------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_DRIVER_DISTRO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_DISTRO_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/VirtualFileSystem.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
comment|/// Distro - Helper class for detecting and classifying Linux distributions.
comment|///
comment|/// This class encapsulates the clang Linux distribution detection mechanism
comment|/// as well as helper functions that match the specific (versioned) results
comment|/// into wider distribution classes.
name|class
name|Distro
block|{
name|public
label|:
enum|enum
name|DistroType
block|{
comment|// NB: Releases of a particular Linux distro should be kept together
comment|// in this enum, because some tests are done by integer comparison against
comment|// the first and last known member in the family, e.g. IsRedHat().
name|ArchLinux
block|,
name|DebianLenny
block|,
name|DebianSqueeze
block|,
name|DebianWheezy
block|,
name|DebianJessie
block|,
name|DebianStretch
block|,
name|Exherbo
block|,
name|RHEL5
block|,
name|RHEL6
block|,
name|RHEL7
block|,
name|Fedora
block|,
name|OpenSUSE
block|,
name|UbuntuHardy
block|,
name|UbuntuIntrepid
block|,
name|UbuntuJaunty
block|,
name|UbuntuKarmic
block|,
name|UbuntuLucid
block|,
name|UbuntuMaverick
block|,
name|UbuntuNatty
block|,
name|UbuntuOneiric
block|,
name|UbuntuPrecise
block|,
name|UbuntuQuantal
block|,
name|UbuntuRaring
block|,
name|UbuntuSaucy
block|,
name|UbuntuTrusty
block|,
name|UbuntuUtopic
block|,
name|UbuntuVivid
block|,
name|UbuntuWily
block|,
name|UbuntuXenial
block|,
name|UbuntuYakkety
block|,
name|UbuntuZesty
block|,
name|UbuntuArtful
block|,
name|UnknownDistro
block|}
enum|;
name|private
label|:
comment|/// The distribution, possibly with specific version.
name|DistroType
name|DistroVal
decl_stmt|;
name|public
label|:
comment|/// @name Constructors
comment|/// @{
comment|/// Default constructor leaves the distribution unknown.
name|Distro
argument_list|()
operator|:
name|DistroVal
argument_list|()
block|{}
comment|/// Constructs a Distro type for specific distribution.
name|Distro
argument_list|(
argument|DistroType D
argument_list|)
operator|:
name|DistroVal
argument_list|(
argument|D
argument_list|)
block|{}
comment|/// Detects the distribution using specified VFS.
name|explicit
name|Distro
argument_list|(
name|clang
operator|::
name|vfs
operator|::
name|FileSystem
operator|&
name|VFS
argument_list|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Distro
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|DistroVal
operator|==
name|Other
operator|.
name|DistroVal
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Distro
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|DistroVal
operator|!=
name|Other
operator|.
name|DistroVal
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|Distro
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|DistroVal
operator|>=
name|Other
operator|.
name|DistroVal
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|Distro
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|DistroVal
operator|<=
name|Other
operator|.
name|DistroVal
return|;
block|}
comment|/// @}
comment|/// @name Convenience Predicates
comment|/// @{
name|bool
name|IsRedhat
argument_list|()
specifier|const
block|{
return|return
name|DistroVal
operator|==
name|Fedora
operator|||
operator|(
name|DistroVal
operator|>=
name|RHEL5
operator|&&
name|DistroVal
operator|<=
name|RHEL7
operator|)
return|;
block|}
name|bool
name|IsOpenSUSE
argument_list|()
specifier|const
block|{
return|return
name|DistroVal
operator|==
name|OpenSUSE
return|;
block|}
name|bool
name|IsDebian
argument_list|()
specifier|const
block|{
return|return
name|DistroVal
operator|>=
name|DebianLenny
operator|&&
name|DistroVal
operator|<=
name|DebianStretch
return|;
block|}
name|bool
name|IsUbuntu
argument_list|()
specifier|const
block|{
return|return
name|DistroVal
operator|>=
name|UbuntuHardy
operator|&&
name|DistroVal
operator|<=
name|UbuntuArtful
return|;
block|}
comment|/// @}
block|}
empty_stmt|;
block|}
comment|// end namespace driver
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

