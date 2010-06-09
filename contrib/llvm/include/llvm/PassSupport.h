begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/PassSupport.h - Pass Support code -------------------*- C++ -*-===//
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
comment|// This file defines stuff that is used to define and "use" Passes.  This file
end_comment

begin_comment
comment|// is automatically #included by Pass.h, so:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//           NO .CPP FILES SHOULD INCLUDE THIS FILE DIRECTLY
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Instead, #include Pass.h.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines Pass registration code and classes used for it.
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
name|LLVM_PASS_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASS_SUPPORT_H
end_define

begin_include
include|#
directive|include
file|"Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetMachine
decl_stmt|;
comment|//===---------------------------------------------------------------------------
comment|/// PassInfo class - An instance of this class exists for every pass known by
comment|/// the system, and can be obtained from a live Pass by calling its
comment|/// getPassInfo() method.  These objects are set up by the RegisterPass<>
comment|/// template, defined below.
comment|///
name|class
name|PassInfo
block|{
name|public
label|:
typedef|typedef
name|Pass
modifier|*
function_decl|(
modifier|*
name|NormalCtor_t
function_decl|)
parameter_list|()
function_decl|;
name|private
label|:
specifier|const
name|char
modifier|*
specifier|const
name|PassName
decl_stmt|;
comment|// Nice name for Pass
specifier|const
name|char
modifier|*
specifier|const
name|PassArgument
decl_stmt|;
comment|// Command Line argument to run this pass
specifier|const
name|intptr_t
name|PassID
decl_stmt|;
specifier|const
name|bool
name|IsCFGOnlyPass
decl_stmt|;
comment|// Pass only looks at the CFG.
specifier|const
name|bool
name|IsAnalysis
decl_stmt|;
comment|// True if an analysis pass.
specifier|const
name|bool
name|IsAnalysisGroup
decl_stmt|;
comment|// True if an analysis group.
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
name|ItfImpl
expr_stmt|;
comment|// Interfaces implemented by this pass
name|NormalCtor_t
name|NormalCtor
decl_stmt|;
name|public
label|:
comment|/// PassInfo ctor - Do not call this directly, this should only be invoked
comment|/// through RegisterPass.
name|PassInfo
argument_list|(
argument|const char *name
argument_list|,
argument|const char *arg
argument_list|,
argument|intptr_t pi
argument_list|,
argument|NormalCtor_t normal =
literal|0
argument_list|,
argument|bool isCFGOnly = false
argument_list|,
argument|bool is_analysis = false
argument_list|)
block|:
name|PassName
argument_list|(
name|name
argument_list|)
operator|,
name|PassArgument
argument_list|(
name|arg
argument_list|)
operator|,
name|PassID
argument_list|(
name|pi
argument_list|)
operator|,
name|IsCFGOnlyPass
argument_list|(
name|isCFGOnly
argument_list|)
operator|,
name|IsAnalysis
argument_list|(
name|is_analysis
argument_list|)
operator|,
name|IsAnalysisGroup
argument_list|(
name|false
argument_list|)
operator|,
name|NormalCtor
argument_list|(
argument|normal
argument_list|)
block|{
name|registerPass
argument_list|()
block|;   }
comment|/// PassInfo ctor - Do not call this directly, this should only be invoked
comment|/// through RegisterPass. This version is for use by analysis groups; it
comment|/// does not auto-register the pass.
name|PassInfo
argument_list|(
argument|const char *name
argument_list|,
argument|intptr_t pi
argument_list|)
operator|:
name|PassName
argument_list|(
name|name
argument_list|)
operator|,
name|PassArgument
argument_list|(
literal|""
argument_list|)
operator|,
name|PassID
argument_list|(
name|pi
argument_list|)
operator|,
name|IsCFGOnlyPass
argument_list|(
name|false
argument_list|)
operator|,
name|IsAnalysis
argument_list|(
name|false
argument_list|)
operator|,
name|IsAnalysisGroup
argument_list|(
name|true
argument_list|)
operator|,
name|NormalCtor
argument_list|(
literal|0
argument_list|)
block|{   }
comment|/// getPassName - Return the friendly name for the pass, never returns null
comment|///
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
name|PassName
return|;
block|}
comment|/// getPassArgument - Return the command line option that may be passed to
comment|/// 'opt' that will cause this pass to be run.  This will return null if there
comment|/// is no argument.
comment|///
specifier|const
name|char
operator|*
name|getPassArgument
argument_list|()
specifier|const
block|{
return|return
name|PassArgument
return|;
block|}
comment|/// getTypeInfo - Return the id object for the pass...
comment|/// TODO : Rename
name|intptr_t
name|getTypeInfo
argument_list|()
specifier|const
block|{
return|return
name|PassID
return|;
block|}
comment|/// Return true if this PassID implements the specified ID pointer.
name|bool
name|isPassID
argument_list|(
name|void
operator|*
name|IDPtr
argument_list|)
decl|const
block|{
return|return
name|PassID
operator|==
operator|(
name|intptr_t
operator|)
name|IDPtr
return|;
block|}
comment|/// isAnalysisGroup - Return true if this is an analysis group, not a normal
comment|/// pass.
comment|///
name|bool
name|isAnalysisGroup
argument_list|()
specifier|const
block|{
return|return
name|IsAnalysisGroup
return|;
block|}
name|bool
name|isAnalysis
argument_list|()
specifier|const
block|{
return|return
name|IsAnalysis
return|;
block|}
comment|/// isCFGOnlyPass - return true if this pass only looks at the CFG for the
comment|/// function.
name|bool
name|isCFGOnlyPass
argument_list|()
specifier|const
block|{
return|return
name|IsCFGOnlyPass
return|;
block|}
comment|/// getNormalCtor - Return a pointer to a function, that when called, creates
comment|/// an instance of the pass and returns it.  This pointer may be null if there
comment|/// is no default constructor for the pass.
comment|///
name|NormalCtor_t
name|getNormalCtor
argument_list|()
specifier|const
block|{
return|return
name|NormalCtor
return|;
block|}
name|void
name|setNormalCtor
parameter_list|(
name|NormalCtor_t
name|Ctor
parameter_list|)
block|{
name|NormalCtor
operator|=
name|Ctor
expr_stmt|;
block|}
comment|/// createPass() - Use this method to create an instance of this pass.
name|Pass
operator|*
name|createPass
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
operator|!
name|isAnalysisGroup
argument_list|()
operator|||
name|NormalCtor
operator|)
operator|&&
literal|"No default implementation found for analysis group!"
argument_list|)
block|;
name|assert
argument_list|(
name|NormalCtor
operator|&&
literal|"Cannot call createPass on PassInfo without default ctor!"
argument_list|)
block|;
return|return
name|NormalCtor
argument_list|()
return|;
block|}
comment|/// addInterfaceImplemented - This method is called when this pass is
comment|/// registered as a member of an analysis group with the RegisterAnalysisGroup
comment|/// template.
comment|///
name|void
name|addInterfaceImplemented
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|ItfPI
parameter_list|)
block|{
name|ItfImpl
operator|.
name|push_back
argument_list|(
name|ItfPI
argument_list|)
expr_stmt|;
block|}
comment|/// getInterfacesImplemented - Return a list of all of the analysis group
comment|/// interfaces implemented by this pass.
comment|///
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|getInterfacesImplemented
argument_list|()
specifier|const
block|{
return|return
name|ItfImpl
return|;
block|}
name|protected
label|:
name|void
name|registerPass
parameter_list|()
function_decl|;
name|void
name|unregisterPass
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|operator
init|=
operator|(
specifier|const
name|PassInfo
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|PassInfo
argument_list|(
specifier|const
name|PassInfo
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|PassName
operator|>
name|Pass
operator|*
name|callDefaultCtor
argument_list|()
block|{
return|return
name|new
name|PassName
argument_list|()
return|;
block|}
comment|//===---------------------------------------------------------------------------
comment|/// RegisterPass<t> template - This template class is used to notify the system
comment|/// that a Pass is available for use, and registers it into the internal
comment|/// database maintained by the PassManager.  Unless this template is used, opt,
comment|/// for example will not be able to see the pass and attempts to create the pass
comment|/// will fail. This template is used in the follow manner (at global scope, in
comment|/// your .cpp file):
comment|///
comment|/// static RegisterPass<YourPassClassName> tmp("passopt", "My Pass Name");
comment|///
comment|/// This statement will cause your pass to be created by calling the default
comment|/// constructor exposed by the pass.  If you have a different constructor that
comment|/// must be called, create a global constructor function (which takes the
comment|/// arguments you need and returns a Pass*) and register your pass like this:
comment|///
comment|/// static RegisterPass<PassClassName> tmp("passopt", "My Name");
comment|///
name|template
operator|<
name|typename
name|passName
operator|>
expr|struct
name|RegisterPass
operator|:
name|public
name|PassInfo
block|{
comment|// Register Pass using default constructor...
name|RegisterPass
argument_list|(
argument|const char *PassArg
argument_list|,
argument|const char *Name
argument_list|,
argument|bool CFGOnly = false
argument_list|,
argument|bool is_analysis = false
argument_list|)
operator|:
name|PassInfo
argument_list|(
argument|Name
argument_list|,
argument|PassArg
argument_list|,
argument|intptr_t(&passName::ID)
argument_list|,
argument|PassInfo::NormalCtor_t(callDefaultCtor<passName>)
argument_list|,
argument|CFGOnly
argument_list|,
argument|is_analysis
argument_list|)
block|{   }
block|}
expr_stmt|;
comment|/// RegisterAnalysisGroup - Register a Pass as a member of an analysis _group_.
comment|/// Analysis groups are used to define an interface (which need not derive from
comment|/// Pass) that is required by passes to do their job.  Analysis Groups differ
comment|/// from normal analyses because any available implementation of the group will
comment|/// be used if it is available.
comment|///
comment|/// If no analysis implementing the interface is available, a default
comment|/// implementation is created and added.  A pass registers itself as the default
comment|/// implementation by specifying 'true' as the second template argument of this
comment|/// class.
comment|///
comment|/// In addition to registering itself as an analysis group member, a pass must
comment|/// register itself normally as well.  Passes may be members of multiple groups
comment|/// and may still be "required" specifically by name.
comment|///
comment|/// The actual interface may also be registered as well (by not specifying the
comment|/// second template argument).  The interface should be registered to associate
comment|/// a nice name with the interface.
comment|///
name|class
name|RegisterAGBase
range|:
name|public
name|PassInfo
block|{
name|protected
operator|:
name|RegisterAGBase
argument_list|(
argument|const char *Name
argument_list|,
argument|intptr_t InterfaceID
argument_list|,
argument|intptr_t PassID =
literal|0
argument_list|,
argument|bool isDefault = false
argument_list|)
block|; }
decl_stmt|;
name|template
operator|<
name|typename
name|Interface
operator|,
name|bool
name|Default
operator|=
name|false
operator|>
expr|struct
name|RegisterAnalysisGroup
operator|:
name|public
name|RegisterAGBase
block|{
name|explicit
name|RegisterAnalysisGroup
argument_list|(
name|PassInfo
operator|&
name|RPB
argument_list|)
operator|:
name|RegisterAGBase
argument_list|(
argument|RPB.getPassName()
argument_list|,
argument|intptr_t(&Interface::ID)
argument_list|,
argument|RPB.getTypeInfo()
argument_list|,
argument|Default
argument_list|)
block|{   }
name|explicit
name|RegisterAnalysisGroup
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|)
operator|:
name|RegisterAGBase
argument_list|(
argument|Name
argument_list|,
argument|intptr_t(&Interface::ID)
argument_list|)
block|{   }
block|}
expr_stmt|;
comment|//===---------------------------------------------------------------------------
comment|/// PassRegistrationListener class - This class is meant to be derived from by
comment|/// clients that are interested in which passes get registered and unregistered
comment|/// at runtime (which can be because of the RegisterPass constructors being run
comment|/// as the program starts up, or may be because a shared object just got
comment|/// loaded).  Deriving from the PassRegistationListener class automatically
comment|/// registers your object to receive callbacks indicating when passes are loaded
comment|/// and removed.
comment|///
struct|struct
name|PassRegistrationListener
block|{
comment|/// PassRegistrationListener ctor - Add the current object to the list of
comment|/// PassRegistrationListeners...
name|PassRegistrationListener
argument_list|()
expr_stmt|;
comment|/// dtor - Remove object from list of listeners...
comment|///
name|virtual
operator|~
name|PassRegistrationListener
argument_list|()
expr_stmt|;
comment|/// Callback functions - These functions are invoked whenever a pass is loaded
comment|/// or removed from the current executable.
comment|///
name|virtual
name|void
name|passRegistered
parameter_list|(
specifier|const
name|PassInfo
modifier|*
parameter_list|)
block|{}
comment|/// enumeratePasses - Iterate over the registered passes, calling the
comment|/// passEnumerate callback on each PassInfo object.
comment|///
name|void
name|enumeratePasses
parameter_list|()
function_decl|;
comment|/// passEnumerate - Callback function invoked when someone calls
comment|/// enumeratePasses on this PassRegistrationListener object.
comment|///
name|virtual
name|void
name|passEnumerate
parameter_list|(
specifier|const
name|PassInfo
modifier|*
parameter_list|)
block|{}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

