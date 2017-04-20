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
name|LLVM_PASSSUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASSSUPPORT_H
end_define

begin_include
include|#
directive|include
file|"Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/InitializePasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Atomic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Threading.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetMachine
decl_stmt|;
define|#
directive|define
name|INITIALIZE_PASS
parameter_list|(
name|passName
parameter_list|,
name|arg
parameter_list|,
name|name
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|)
define|\
value|static void *initialize##passName##PassOnce(PassRegistry&Registry) {        \     PassInfo *PI = new PassInfo(                                               \         name, arg,&passName::ID,                                              \         PassInfo::NormalCtor_t(callDefaultCtor<passName>), cfg, analysis);     \     Registry.registerPass(*PI, true);                                          \     return PI;                                                                 \   }                                                                            \   static llvm::once_flag Initialize##passName##PassFlag;                       \   void llvm::initialize##passName##Pass(PassRegistry&Registry) {              \     llvm::call_once(Initialize##passName##PassFlag,                            \                     initialize##passName##PassOnce, std::ref(Registry));       \   }
define|#
directive|define
name|INITIALIZE_PASS_BEGIN
parameter_list|(
name|passName
parameter_list|,
name|arg
parameter_list|,
name|name
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|)
define|\
value|static void *initialize##passName##PassOnce(PassRegistry&Registry) {
define|#
directive|define
name|INITIALIZE_PASS_DEPENDENCY
parameter_list|(
name|depName
parameter_list|)
value|initialize##depName##Pass(Registry);
define|#
directive|define
name|INITIALIZE_AG_DEPENDENCY
parameter_list|(
name|depName
parameter_list|)
define|\
value|initialize##depName##AnalysisGroup(Registry);
define|#
directive|define
name|INITIALIZE_PASS_END
parameter_list|(
name|passName
parameter_list|,
name|arg
parameter_list|,
name|name
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|)
define|\
value|PassInfo *PI = new PassInfo(                                                 \       name, arg,&passName::ID,                                                \       PassInfo::NormalCtor_t(callDefaultCtor<passName>), cfg, analysis);       \   Registry.registerPass(*PI, true);                                            \   return PI;                                                                   \   }                                                                            \   static llvm::once_flag Initialize##passName##PassFlag;                       \   void llvm::initialize##passName##Pass(PassRegistry&Registry) {              \     llvm::call_once(Initialize##passName##PassFlag,                            \                     initialize##passName##PassOnce, std::ref(Registry));       \   }
define|#
directive|define
name|INITIALIZE_PASS_WITH_OPTIONS
parameter_list|(
name|PassName
parameter_list|,
name|Arg
parameter_list|,
name|Name
parameter_list|,
name|Cfg
parameter_list|,
name|Analysis
parameter_list|)
define|\
value|INITIALIZE_PASS_BEGIN(PassName, Arg, Name, Cfg, Analysis)                    \   PassName::registerOptions();                                                 \   INITIALIZE_PASS_END(PassName, Arg, Name, Cfg, Analysis)
define|#
directive|define
name|INITIALIZE_PASS_WITH_OPTIONS_BEGIN
parameter_list|(
name|PassName
parameter_list|,
name|Arg
parameter_list|,
name|Name
parameter_list|,
name|Cfg
parameter_list|,
name|Analysis
parameter_list|)
define|\
value|INITIALIZE_PASS_BEGIN(PassName, Arg, Name, Cfg, Analysis)                    \   PassName::registerOptions();
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
name|template
operator|<
name|typename
name|PassName
operator|>
name|Pass
operator|*
name|callTargetMachineCtor
argument_list|(
argument|TargetMachine *TM
argument_list|)
block|{
return|return
name|new
name|PassName
argument_list|(
name|TM
argument_list|)
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
comment|/// constructor exposed by the pass.
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
argument|StringRef PassArg
argument_list|,
argument|StringRef Name
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
argument|&passName::ID
argument_list|,
argument|PassInfo::NormalCtor_t(callDefaultCtor<passName>)
argument_list|,
argument|CFGOnly
argument_list|,
argument|is_analysis
argument_list|)
block|{
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
operator|->
name|registerPass
argument_list|(
operator|*
name|this
argument_list|)
block|;   }
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
name|public
operator|:
name|RegisterAGBase
argument_list|(
argument|StringRef Name
argument_list|,
argument|const void *InterfaceID
argument_list|,
argument|const void *PassID = nullptr
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
argument|&Interface::ID
argument_list|,
argument|RPB.getTypeInfo()
argument_list|,
argument|Default
argument_list|)
block|{}
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
argument|&Interface::ID
argument_list|)
block|{}
block|}
expr_stmt|;
define|#
directive|define
name|INITIALIZE_ANALYSIS_GROUP
parameter_list|(
name|agName
parameter_list|,
name|name
parameter_list|,
name|defaultPass
parameter_list|)
define|\
value|static void *initialize##agName##AnalysisGroupOnce(PassRegistry&Registry) { \     initialize##defaultPass##Pass(Registry);                                   \     PassInfo *AI = new PassInfo(name,&agName::ID);                            \     Registry.registerAnalysisGroup(&agName::ID, 0, *AI, false, true);          \     return AI;                                                                 \   }                                                                            \   static llvm::once_flag Initialize##agName##AnalysisGroupFlag;                \   void llvm::initialize##agName##AnalysisGroup(PassRegistry&Registry) {       \     llvm::call_once(Initialize##agName##AnalysisGroupFlag,                     \                     initialize##agName##AnalysisGroupOnce,                     \                     std::ref(Registry));                                       \   }
define|#
directive|define
name|INITIALIZE_AG_PASS
parameter_list|(
name|passName
parameter_list|,
name|agName
parameter_list|,
name|arg
parameter_list|,
name|name
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|,
name|def
parameter_list|)
define|\
value|static void *initialize##passName##PassOnce(PassRegistry&Registry) {        \     if (!def)                                                                  \       initialize##agName##AnalysisGroup(Registry);                             \     PassInfo *PI = new PassInfo(                                               \         name, arg,&passName::ID,                                              \         PassInfo::NormalCtor_t(callDefaultCtor<passName>), cfg, analysis);     \     Registry.registerPass(*PI, true);                                          \                                                                                \     PassInfo *AI = new PassInfo(name,&agName::ID);                            \     Registry.registerAnalysisGroup(&agName::ID,&passName::ID, *AI, def,       \                                    true);                                      \     return AI;                                                                 \   }                                                                            \   static llvm::once_flag Initialize##passName##PassFlag;                       \   void llvm::initialize##passName##Pass(PassRegistry&Registry) {              \     llvm::call_once(Initialize##passName##PassFlag,                            \                     initialize##passName##PassOnce, std::ref(Registry));       \   }
define|#
directive|define
name|INITIALIZE_AG_PASS_BEGIN
parameter_list|(
name|passName
parameter_list|,
name|agName
parameter_list|,
name|arg
parameter_list|,
name|n
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|,
name|def
parameter_list|)
define|\
value|static void *initialize##passName##PassOnce(PassRegistry&Registry) {        \     if (!def)                                                                  \       initialize##agName##AnalysisGroup(Registry);
define|#
directive|define
name|INITIALIZE_AG_PASS_END
parameter_list|(
name|passName
parameter_list|,
name|agName
parameter_list|,
name|arg
parameter_list|,
name|n
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|,
name|def
parameter_list|)
define|\
value|PassInfo *PI = new PassInfo(                                                 \       n, arg,&passName::ID,                                                   \       PassInfo::NormalCtor_t(callDefaultCtor<passName>), cfg, analysis);       \   Registry.registerPass(*PI, true);                                            \                                                                                \   PassInfo *AI = new PassInfo(n,&agName::ID);                                 \   Registry.registerAnalysisGroup(&agName::ID,&passName::ID, *AI, def, true);  \   return AI;                                                                   \   }                                                                            \   static llvm::once_flag Initialize##passName##PassFlag;                       \   void llvm::initialize##passName##Pass(PassRegistry&Registry) {              \     llvm::call_once(Initialize##passName##PassFlag,                            \                     initialize##passName##PassOnce, std::ref(Registry));       \   }
comment|//===---------------------------------------------------------------------------
comment|/// PassRegistrationListener class - This class is meant to be derived from by
comment|/// clients that are interested in which passes get registered and unregistered
comment|/// at runtime (which can be because of the RegisterPass constructors being run
comment|/// as the program starts up, or may be because a shared object just got
comment|/// loaded).
comment|///
struct|struct
name|PassRegistrationListener
block|{
name|PassRegistrationListener
argument_list|()
block|{}
name|virtual
operator|~
name|PassRegistrationListener
argument_list|()
block|{}
comment|/// Callback functions - These functions are invoked whenever a pass is loaded
comment|/// or removed from the current executable.
comment|///
name|virtual
name|void
name|passRegistered
argument_list|(
argument|const PassInfo *
argument_list|)
block|{}
comment|/// enumeratePasses - Iterate over the registered passes, calling the
comment|/// passEnumerate callback on each PassInfo object.
comment|///
name|void
name|enumeratePasses
argument_list|()
expr_stmt|;
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

