begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PseudoTerminal.h ----------------------------------------*- C++ -*-===//
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
name|LLDB_HOST_PSEUDOTERMINAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_HOST_PSEUDOTERMINAL_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_utility
block|{
comment|//----------------------------------------------------------------------
comment|/// @class PseudoTerminal PseudoTerminal.h "lldb/Host/PseudoTerminal.h"
comment|/// @brief A pseudo terminal helper class.
comment|///
comment|/// The pseudo terminal class abstracts the use of pseudo terminals on
comment|/// the host system.
comment|//----------------------------------------------------------------------
name|class
name|PseudoTerminal
block|{
name|public
label|:
enum|enum
block|{
name|invalid_fd
init|=
operator|-
literal|1
comment|///< Invalid file descriptor value
block|}
enum|;
comment|//------------------------------------------------------------------
comment|/// Default constructor
comment|///
comment|/// Constructs this object with invalid master and slave file
comment|/// descriptors.
comment|//------------------------------------------------------------------
name|PseudoTerminal
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|///
comment|/// The destructor will close the master and slave file descriptors
comment|/// if they are valid and ownership has not been released using
comment|/// one of:
comment|/// @li PseudoTerminal::ReleaseMasterFileDescriptor()
comment|/// @li PseudoTerminal::ReleaseSaveFileDescriptor()
comment|//------------------------------------------------------------------
operator|~
name|PseudoTerminal
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Close the master file descriptor if it is valid.
comment|//------------------------------------------------------------------
name|void
name|CloseMasterFileDescriptor
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Close the slave file descriptor if it is valid.
comment|//------------------------------------------------------------------
name|void
name|CloseSlaveFileDescriptor
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Fork a child process that uses pseudo terminals for its stdio.
comment|///
comment|/// In the parent process, a call to this function results in a pid
comment|/// being returned. If the pid is valid, the master file descriptor
comment|/// can be used for read/write access to stdio of the child process.
comment|///
comment|/// In the child process the stdin/stdout/stderr will already be
comment|/// routed to the slave pseudo terminal and the master file
comment|/// descriptor will be closed as it is no longer needed by the child
comment|/// process.
comment|///
comment|/// This class will close the file descriptors for the master/slave
comment|/// when the destructor is called. The file handles can be released
comment|/// using either:
comment|/// @li PseudoTerminal::ReleaseMasterFileDescriptor()
comment|/// @li PseudoTerminal::ReleaseSaveFileDescriptor()
comment|///
comment|/// @param[out] error
comment|///     An pointer to an error that can describe any errors that
comment|///     occur. This can be NULL if no error status is desired.
comment|///
comment|/// @return
comment|///     @li \b Parent process: a child process ID that is greater
comment|///         than zero, or -1 if the fork fails.
comment|///     @li \b Child process: zero.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|pid_t
name|Fork
argument_list|(
argument|char *error_str
argument_list|,
argument|size_t error_len
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// The master file descriptor accessor.
comment|///
comment|/// This object retains ownership of the master file descriptor when
comment|/// this accessor is used. Users can call the member function
comment|/// PseudoTerminal::ReleaseMasterFileDescriptor() if this
comment|/// object should release ownership of the slave file descriptor.
comment|///
comment|/// @return
comment|///     The master file descriptor, or PseudoTerminal::invalid_fd
comment|///     if the master file  descriptor is not currently valid.
comment|///
comment|/// @see PseudoTerminal::ReleaseMasterFileDescriptor()
comment|//------------------------------------------------------------------
name|int
name|GetMasterFileDescriptor
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// The slave file descriptor accessor.
comment|///
comment|/// This object retains ownership of the slave file descriptor when
comment|/// this accessor is used. Users can call the member function
comment|/// PseudoTerminal::ReleaseSlaveFileDescriptor() if this
comment|/// object should release ownership of the slave file descriptor.
comment|///
comment|/// @return
comment|///     The slave file descriptor, or PseudoTerminal::invalid_fd
comment|///     if the slave file descriptor is not currently valid.
comment|///
comment|/// @see PseudoTerminal::ReleaseSlaveFileDescriptor()
comment|//------------------------------------------------------------------
name|int
name|GetSlaveFileDescriptor
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the name of the slave pseudo terminal.
comment|///
comment|/// A master pseudo terminal should already be valid prior to
comment|/// calling this function.
comment|///
comment|/// @param[out] error
comment|///     An pointer to an error that can describe any errors that
comment|///     occur. This can be NULL if no error status is desired.
comment|///
comment|/// @return
comment|///     The name of the slave pseudo terminal as a NULL terminated
comment|///     C. This string that comes from static memory, so a copy of
comment|///     the string should be made as subsequent calls can change
comment|///     this value. NULL is returned if this object doesn't have
comment|///     a valid master pseudo terminal opened or if the call to
comment|///     \c ptsname() fails.
comment|///
comment|/// @see PseudoTerminal::OpenFirstAvailableMaster()
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetSlaveName
argument_list|(
name|char
operator|*
name|error_str
argument_list|,
name|size_t
name|error_len
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Open the first available pseudo terminal.
comment|///
comment|/// Opens the first available pseudo terminal with \a oflag as the
comment|/// permissions. The opened master file descriptor is stored in this
comment|/// object and can be accessed by calling the
comment|/// PseudoTerminal::GetMasterFileDescriptor() accessor. Clients
comment|/// can call the PseudoTerminal::ReleaseMasterFileDescriptor()
comment|/// accessor function if they wish to use the master file descriptor
comment|/// beyond the lifespan of this object.
comment|///
comment|/// If this object still has a valid master file descriptor when its
comment|/// destructor is called, it will close it.
comment|///
comment|/// @param[in] oflag
comment|///     Flags to use when calling \c posix_openpt(\a oflag).
comment|///     A value of "O_RDWR|O_NOCTTY" is suggested.
comment|///
comment|/// @param[out] error
comment|///     An pointer to an error that can describe any errors that
comment|///     occur. This can be NULL if no error status is desired.
comment|///
comment|/// @return
comment|///     @li \b true when the master files descriptor is
comment|///         successfully opened.
comment|///     @li \b false if anything goes wrong.
comment|///
comment|/// @see PseudoTerminal::GetMasterFileDescriptor()
comment|/// @see PseudoTerminal::ReleaseMasterFileDescriptor()
comment|//------------------------------------------------------------------
name|bool
name|OpenFirstAvailableMaster
parameter_list|(
name|int
name|oflag
parameter_list|,
name|char
modifier|*
name|error_str
parameter_list|,
name|size_t
name|error_len
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Open the slave for the current master pseudo terminal.
comment|///
comment|/// A master pseudo terminal should already be valid prior to
comment|/// calling this function. The opened slave file descriptor is
comment|/// stored in this object and can be accessed by calling the
comment|/// PseudoTerminal::GetSlaveFileDescriptor() accessor. Clients
comment|/// can call the PseudoTerminal::ReleaseSlaveFileDescriptor()
comment|/// accessor function if they wish to use the slave file descriptor
comment|/// beyond the lifespan of this object.
comment|///
comment|/// If this object still has a valid slave file descriptor when its
comment|/// destructor is called, it will close it.
comment|///
comment|/// @param[in] oflag
comment|///     Flags to use when calling \c open(\a oflag).
comment|///
comment|/// @param[out] error
comment|///     An pointer to an error that can describe any errors that
comment|///     occur. This can be NULL if no error status is desired.
comment|///
comment|/// @return
comment|///     @li \b true when the master files descriptor is
comment|///         successfully opened.
comment|///     @li \b false if anything goes wrong.
comment|///
comment|/// @see PseudoTerminal::OpenFirstAvailableMaster()
comment|/// @see PseudoTerminal::GetSlaveFileDescriptor()
comment|/// @see PseudoTerminal::ReleaseSlaveFileDescriptor()
comment|//------------------------------------------------------------------
name|bool
name|OpenSlave
parameter_list|(
name|int
name|oflag
parameter_list|,
name|char
modifier|*
name|error_str
parameter_list|,
name|size_t
name|error_len
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Release the master file descriptor.
comment|///
comment|/// Releases ownership of the master pseudo terminal file descriptor
comment|/// without closing it. The destructor for this class will close the
comment|/// master file descriptor if the ownership isn't released using this
comment|/// call and the master file descriptor has been opened.
comment|///
comment|/// @return
comment|///     The master file descriptor, or PseudoTerminal::invalid_fd
comment|///     if the mast file descriptor is not currently valid.
comment|//------------------------------------------------------------------
name|int
name|ReleaseMasterFileDescriptor
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Release the slave file descriptor.
comment|///
comment|/// Release ownership of the slave pseudo terminal file descriptor
comment|/// without closing it. The destructor for this class will close the
comment|/// slave file descriptor if the ownership isn't released using this
comment|/// call and the slave file descriptor has been opened.
comment|///
comment|/// @return
comment|///     The slave file descriptor, or PseudoTerminal::invalid_fd
comment|///     if the slave file descriptor is not currently valid.
comment|//------------------------------------------------------------------
name|int
name|ReleaseSlaveFileDescriptor
parameter_list|()
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|int
name|m_master_fd
decl_stmt|;
comment|///< The file descriptor for the master.
name|int
name|m_slave_fd
decl_stmt|;
comment|///< The file descriptor for the slave.
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PseudoTerminal
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_utility
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_PseudoTerminal_h_
end_comment

end_unit

