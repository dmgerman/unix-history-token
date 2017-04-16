begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnixSignals.h -------------------------------------------*- C++ -*-===//
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
name|lldb_UnixSignals_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_UnixSignals_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|UnixSignals
block|{
name|public
label|:
specifier|static
name|lldb
operator|::
name|UnixSignalsSP
name|Create
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|UnixSignals
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|UnixSignals
argument_list|()
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetSignalAsCString
argument_list|(
name|int32_t
name|signo
argument_list|)
decl|const
decl_stmt|;
name|bool
name|SignalIsValid
argument_list|(
name|int32_t
name|signo
argument_list|)
decl|const
decl_stmt|;
name|int32_t
name|GetSignalNumberFromName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetSignalInfo
argument_list|(
name|int32_t
name|signo
argument_list|,
name|bool
operator|&
name|should_suppress
argument_list|,
name|bool
operator|&
name|should_stop
argument_list|,
name|bool
operator|&
name|should_notify
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetShouldSuppress
argument_list|(
name|int32_t
name|signo
argument_list|)
decl|const
decl_stmt|;
name|bool
name|SetShouldSuppress
parameter_list|(
name|int32_t
name|signo
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
name|bool
name|SetShouldSuppress
parameter_list|(
specifier|const
name|char
modifier|*
name|signal_name
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
name|bool
name|GetShouldStop
argument_list|(
name|int32_t
name|signo
argument_list|)
decl|const
decl_stmt|;
name|bool
name|SetShouldStop
parameter_list|(
name|int32_t
name|signo
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
name|bool
name|SetShouldStop
parameter_list|(
specifier|const
name|char
modifier|*
name|signal_name
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
name|bool
name|GetShouldNotify
argument_list|(
name|int32_t
name|signo
argument_list|)
decl|const
decl_stmt|;
name|bool
name|SetShouldNotify
parameter_list|(
name|int32_t
name|signo
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
name|bool
name|SetShouldNotify
parameter_list|(
specifier|const
name|char
modifier|*
name|signal_name
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
comment|// These provide an iterator through the signals available on this system.
comment|// Call GetFirstSignalNumber to get the first entry, then iterate on
comment|// GetNextSignalNumber
comment|// till you get back LLDB_INVALID_SIGNAL_NUMBER.
name|int32_t
name|GetFirstSignalNumber
argument_list|()
specifier|const
expr_stmt|;
name|int32_t
name|GetNextSignalNumber
argument_list|(
name|int32_t
name|current_signal
argument_list|)
decl|const
decl_stmt|;
name|int32_t
name|GetNumSignals
argument_list|()
specifier|const
expr_stmt|;
name|int32_t
name|GetSignalAtIndex
argument_list|(
name|int32_t
name|index
argument_list|)
decl|const
decl_stmt|;
name|ConstString
name|GetShortName
argument_list|(
name|ConstString
name|name
argument_list|)
decl|const
decl_stmt|;
comment|// We assume that the elements of this object are constant once it is
comment|// constructed,
comment|// since a process should never need to add or remove symbols as it runs.  So
comment|// don't
comment|// call these functions anywhere but the constructor of your subclass of
comment|// UnixSignals or in
comment|// your Process Plugin's GetUnixSignals method before you return the
comment|// UnixSignal object.
name|void
name|AddSignal
parameter_list|(
name|int
name|signo
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bool
name|default_suppress
parameter_list|,
name|bool
name|default_stop
parameter_list|,
name|bool
name|default_notify
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
specifier|const
name|char
modifier|*
name|alias
init|=
name|nullptr
parameter_list|)
function_decl|;
name|void
name|RemoveSignal
parameter_list|(
name|int
name|signo
parameter_list|)
function_decl|;
comment|// Returns a current version of the data stored in this class.
comment|// Version gets incremented each time Set... method is called.
name|uint64_t
name|GetVersion
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns a vector of signals that meet criteria provided in arguments.
comment|// Each should_[suppress|stop|notify] flag can be
comment|// None  - no filtering by this flag
comment|// true  - only signals that have it set to true are returned
comment|// false - only signals that have it set to true are returned
name|std
operator|::
name|vector
operator|<
name|int32_t
operator|>
name|GetFilteredSignals
argument_list|(
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|should_suppress
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|should_stop
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|should_notify
argument_list|)
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from UnixSignals can see and modify these
comment|//------------------------------------------------------------------
struct|struct
name|Signal
block|{
name|ConstString
name|m_name
decl_stmt|;
name|ConstString
name|m_alias
decl_stmt|;
name|std
operator|::
name|string
name|m_description
expr_stmt|;
name|bool
name|m_suppress
range|:
literal|1
decl_stmt|,
name|m_stop
range|:
literal|1
decl_stmt|,
name|m_notify
range|:
literal|1
decl_stmt|;
name|Signal
argument_list|(
argument|const char *name
argument_list|,
argument|bool default_suppress
argument_list|,
argument|bool default_stop
argument_list|,
argument|bool default_notify
argument_list|,
argument|const char *description
argument_list|,
argument|const char *alias
argument_list|)
empty_stmt|;
operator|~
name|Signal
argument_list|()
block|{}
block|}
struct|;
name|virtual
name|void
name|Reset
parameter_list|()
function_decl|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|int32_t
operator|,
name|Signal
operator|>
name|collection
expr_stmt|;
name|collection
name|m_signals
decl_stmt|;
comment|// This version gets incremented every time something is changing in
comment|// this class, including when we call AddSignal from the constructor.
comment|// So after the object is constructed m_version is going to be> 0
comment|// if it has at least one signal registered in it.
name|uint64_t
name|m_version
init|=
literal|0
decl_stmt|;
comment|// GDBRemote signals need to be copyable.
name|UnixSignals
argument_list|(
specifier|const
name|UnixSignals
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|UnixSignals
modifier|&
name|operator
init|=
operator|(
specifier|const
name|UnixSignals
operator|&
name|rhs
operator|)
operator|=
name|delete
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_UnixSignals_h_
end_comment

end_unit

