begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LibCallSemantics.h - Describe library semantics --------------------===//
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
comment|// This file defines interfaces that can be used to describe language specific
end_comment

begin_comment
comment|// runtime library interfaces (e.g. libc, libm, etc) to LLVM optimizers.
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
name|LLVM_ANALYSIS_LIBCALLSEMANTICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LIBCALLSEMANTICS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|InvokeInst
decl_stmt|;
comment|/// LibCallLocationInfo - This struct describes a set of memory locations that
comment|/// are accessed by libcalls.  Identification of a location is doing with a
comment|/// simple callback function.
comment|///
comment|/// For example, the LibCallInfo may be set up to model the behavior of
comment|/// standard libm functions.  The location that they may be interested in is
comment|/// an abstract location that represents errno for the current target.  In
comment|/// this case, a location for errno is anything such that the predicate
comment|/// returns true.  On Mac OS X, this predicate would return true if the
comment|/// pointer is the result of a call to "__error()".
comment|///
comment|/// Locations can also be defined in a constant-sensitive way.  For example,
comment|/// it is possible to define a location that returns true iff it is passed
comment|/// into the call as a specific argument.  This is useful for modeling things
comment|/// like "printf", which can store to memory, but only through pointers passed
comment|/// with a '%n' constraint.
comment|///
struct|struct
name|LibCallLocationInfo
block|{
comment|// TODO: Flags: isContextSensitive etc.
comment|/// isLocation - Return a LocResult if the specified pointer refers to this
comment|/// location for the specified call site.  This returns "Yes" if we can tell
comment|/// that the pointer *does definitely* refer to the location, "No" if we can
comment|/// tell that the location *definitely does not* refer to the location, and
comment|/// returns "Unknown" if we cannot tell for certain.
enum|enum
name|LocResult
block|{
name|Yes
block|,
name|No
block|,
name|Unknown
block|}
enum|;
name|LocResult
function_decl|(
modifier|*
name|isLocation
function_decl|)
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// LibCallFunctionInfo - Each record in the array of FunctionInfo structs
comment|/// records the behavior of one libcall that is known by the optimizer.  This
comment|/// captures things like the side effects of the call.  Side effects are
comment|/// modeled both universally (in the readnone/readonly) sense, but also
comment|/// potentially against a set of abstract locations defined by the optimizer.
comment|/// This allows an optimizer to define that some libcall (e.g. sqrt) is
comment|/// side-effect free except that it might modify errno (thus, the call is
comment|/// *not* universally readonly).  Or it might say that the side effects
comment|/// are unknown other than to say that errno is not modified.
comment|///
struct|struct
name|LibCallFunctionInfo
block|{
comment|/// Name - This is the name of the libcall this describes.
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|/// TODO: Constant folding function: Constant* vector -> Constant*.
comment|/// UniversalBehavior - This captures the absolute mod/ref behavior without
comment|/// any specific context knowledge.  For example, if the function is known
comment|/// to be readonly, this would be set to 'ref'.  If known to be readnone,
comment|/// this is set to NoModRef.
name|AliasAnalysis
operator|::
name|ModRefResult
name|UniversalBehavior
expr_stmt|;
comment|/// LocationMRInfo - This pair captures info about whether a specific
comment|/// location is modified or referenced by a libcall.
struct|struct
name|LocationMRInfo
block|{
comment|/// LocationID - ID # of the accessed location or ~0U for array end.
name|unsigned
name|LocationID
decl_stmt|;
comment|/// MRInfo - Mod/Ref info for this location.
name|AliasAnalysis
operator|::
name|ModRefResult
name|MRInfo
expr_stmt|;
block|}
struct|;
comment|/// DetailsType - Indicate the sense of the LocationDetails array.  This
comment|/// controls how the LocationDetails array is interpreted.
enum|enum
block|{
comment|/// DoesOnly - If DetailsType is set to DoesOnly, then we know that the
comment|/// *only* mod/ref behavior of this function is captured by the
comment|/// LocationDetails array.  If we are trying to say that 'sqrt' can only
comment|/// modify errno, we'd have the {errnoloc,mod} in the LocationDetails
comment|/// array and have DetailsType set to DoesOnly.
name|DoesOnly
block|,
comment|/// DoesNot - If DetailsType is set to DoesNot, then the sense of the
comment|/// LocationDetails array is completely inverted.  This means that we *do
comment|/// not* know everything about the side effects of this libcall, but we do
comment|/// know things that the libcall cannot do.  This is useful for complex
comment|/// functions like 'ctime' which have crazy mod/ref behavior, but are
comment|/// known to never read or write errno.  In this case, we'd have
comment|/// {errnoloc,modref} in the LocationDetails array and DetailsType would
comment|/// be set to DoesNot, indicating that ctime does not read or write the
comment|/// errno location.
name|DoesNot
block|}
name|DetailsType
enum|;
comment|/// LocationDetails - This is a pointer to an array of LocationMRInfo
comment|/// structs which indicates the behavior of the libcall w.r.t. specific
comment|/// locations.  For example, if this libcall is known to only modify
comment|/// 'errno', it would have a LocationDetails array with the errno ID and
comment|/// 'mod' in it.  See the DetailsType field for how this is interpreted.
comment|///
comment|/// In the "DoesOnly" case, this information is 'may' information for: there
comment|/// is no guarantee that the specified side effect actually does happen,
comment|/// just that it could.  In the "DoesNot" case, this is 'must not' info.
comment|///
comment|/// If this pointer is null, no details are known.
comment|///
specifier|const
name|LocationMRInfo
modifier|*
name|LocationDetails
decl_stmt|;
block|}
struct|;
comment|/// LibCallInfo - Abstract interface to query about library call information.
comment|/// Instances of this class return known information about some set of
comment|/// libcalls.
comment|///
name|class
name|LibCallInfo
block|{
comment|// Implementation details of this object, private.
name|mutable
name|void
modifier|*
name|Impl
decl_stmt|;
name|mutable
specifier|const
name|LibCallLocationInfo
modifier|*
name|Locations
decl_stmt|;
name|mutable
name|unsigned
name|NumLocations
decl_stmt|;
name|public
label|:
name|LibCallInfo
argument_list|()
operator|:
name|Impl
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Locations
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumLocations
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|LibCallInfo
argument_list|()
expr_stmt|;
comment|//===------------------------------------------------------------------===//
comment|//  Accessor Methods: Efficient access to contained data.
comment|//===------------------------------------------------------------------===//
comment|/// getLocationInfo - Return information about the specified LocationID.
specifier|const
name|LibCallLocationInfo
modifier|&
name|getLocationInfo
argument_list|(
name|unsigned
name|LocID
argument_list|)
decl|const
decl_stmt|;
comment|/// getFunctionInfo - Return the LibCallFunctionInfo object corresponding to
comment|/// the specified function if we have it.  If not, return null.
specifier|const
name|LibCallFunctionInfo
modifier|*
name|getFunctionInfo
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|//  Implementation Methods: Subclasses should implement these.
comment|//===------------------------------------------------------------------===//
comment|/// getLocationInfo - Return descriptors for the locations referenced by
comment|/// this set of libcalls.
name|virtual
name|unsigned
name|getLocationInfo
argument_list|(
specifier|const
name|LibCallLocationInfo
operator|*
operator|&
name|Array
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
comment|/// getFunctionInfoArray - Return an array of descriptors that describe the
comment|/// set of libcalls represented by this LibCallInfo object.  This array is
comment|/// terminated by an entry with a NULL name.
name|virtual
specifier|const
name|LibCallFunctionInfo
operator|*
name|getFunctionInfoArray
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|enum
name|class
name|EHPersonality
block|{
name|Unknown
operator|,
name|GNU_Ada
operator|,
name|GNU_C
operator|,
name|GNU_CXX
operator|,
name|GNU_ObjC
operator|,
name|MSVC_X86SEH
operator|,
name|MSVC_Win64SEH
operator|,
name|MSVC_CXX
operator|,
block|}
empty_stmt|;
comment|/// \brief See if the given exception handling personality function is one
comment|/// that we understand.  If so, return a description of it; otherwise return
comment|/// Unknown.
name|EHPersonality
name|classifyEHPersonality
parameter_list|(
specifier|const
name|Value
modifier|*
name|Pers
parameter_list|)
function_decl|;
comment|/// \brief Returns true if this personality function catches asynchronous
comment|/// exceptions.
specifier|inline
name|bool
name|isAsynchronousEHPersonality
parameter_list|(
name|EHPersonality
name|Pers
parameter_list|)
block|{
comment|// The two SEH personality functions can catch asynch exceptions. We assume
comment|// unknown personalities don't catch asynch exceptions.
switch|switch
condition|(
name|Pers
condition|)
block|{
case|case
name|EHPersonality
operator|::
name|MSVC_X86SEH
case|:
case|case
name|EHPersonality
operator|::
name|MSVC_Win64SEH
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid enum"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Returns true if this is an MSVC personality function.
specifier|inline
name|bool
name|isMSVCEHPersonality
parameter_list|(
name|EHPersonality
name|Pers
parameter_list|)
block|{
comment|// The two SEH personality functions can catch asynch exceptions. We assume
comment|// unknown personalities don't catch asynch exceptions.
switch|switch
condition|(
name|Pers
condition|)
block|{
case|case
name|EHPersonality
operator|::
name|MSVC_CXX
case|:
case|case
name|EHPersonality
operator|::
name|MSVC_X86SEH
case|:
case|case
name|EHPersonality
operator|::
name|MSVC_Win64SEH
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid enum"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Return true if this personality may be safely removed if there
comment|/// are no invoke instructions remaining in the current function.
specifier|inline
name|bool
name|isNoOpWithoutInvoke
parameter_list|(
name|EHPersonality
name|Pers
parameter_list|)
block|{
switch|switch
condition|(
name|Pers
condition|)
block|{
case|case
name|EHPersonality
operator|::
name|Unknown
case|:
return|return
name|false
return|;
comment|// All known personalities currently have this behavior
default|default:
return|return
name|true
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid enum"
argument_list|)
expr_stmt|;
block|}
name|bool
name|canSimplifyInvokeNoUnwind
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

