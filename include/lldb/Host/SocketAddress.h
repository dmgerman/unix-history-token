begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SocketAddress.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_SocketAddress_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SocketAddress_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|"lldb/Host/windows/windows.h"
end_include

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include

begin_typedef
typedef|typedef
name|ADDRESS_FAMILY
name|sa_family_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SocketAddress
block|{
name|public
label|:
comment|//----------------------------------------------------------------------------
comment|// Static method to get all address information for a host and/or service
comment|//----------------------------------------------------------------------------
specifier|static
name|std
operator|::
name|vector
operator|<
name|SocketAddress
operator|>
name|GetAddressInfo
argument_list|(
specifier|const
name|char
operator|*
name|hostname
argument_list|,
specifier|const
name|char
operator|*
name|servname
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|SocketAddress
argument_list|()
expr_stmt|;
name|SocketAddress
argument_list|(
specifier|const
expr|struct
name|addrinfo
operator|*
name|addr_info
argument_list|)
expr_stmt|;
name|SocketAddress
argument_list|(
specifier|const
expr|struct
name|sockaddr
operator|&
name|s
argument_list|)
expr_stmt|;
name|SocketAddress
argument_list|(
specifier|const
expr|struct
name|sockaddr_in
operator|&
name|s
argument_list|)
expr_stmt|;
name|SocketAddress
argument_list|(
specifier|const
expr|struct
name|sockaddr_in6
operator|&
name|s
argument_list|)
expr_stmt|;
name|SocketAddress
argument_list|(
specifier|const
expr|struct
name|sockaddr_storage
operator|&
name|s
argument_list|)
expr_stmt|;
name|SocketAddress
argument_list|(
specifier|const
name|SocketAddress
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SocketAddress
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
specifier|const
name|SocketAddress
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SocketAddress
operator|&
name|rhs
operator|)
decl_stmt|;
specifier|const
name|SocketAddress
modifier|&
name|operator
init|=
operator|(
specifier|const
expr|struct
name|addrinfo
operator|*
name|addr_info
operator|)
decl_stmt|;
specifier|const
name|SocketAddress
modifier|&
name|operator
init|=
operator|(
specifier|const
expr|struct
name|sockaddr
operator|&
name|s
operator|)
decl_stmt|;
specifier|const
name|SocketAddress
modifier|&
name|operator
init|=
operator|(
specifier|const
expr|struct
name|sockaddr_in
operator|&
name|s
operator|)
decl_stmt|;
specifier|const
name|SocketAddress
modifier|&
name|operator
init|=
operator|(
specifier|const
expr|struct
name|sockaddr_in6
operator|&
name|s
operator|)
decl_stmt|;
specifier|const
name|SocketAddress
modifier|&
name|operator
init|=
operator|(
specifier|const
expr|struct
name|sockaddr_storage
operator|&
name|s
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SocketAddress
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SocketAddress
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Clear the contents of this socket address
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Get the length for the current socket address family
comment|//------------------------------------------------------------------
name|socklen_t
name|GetLength
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Get the max length for the largest socket address supported.
comment|//------------------------------------------------------------------
specifier|static
name|socklen_t
name|GetMaxLength
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Get the socket address family
comment|//------------------------------------------------------------------
name|sa_family_t
name|GetFamily
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Set the socket address family
comment|//------------------------------------------------------------------
name|void
name|SetFamily
parameter_list|(
name|sa_family_t
name|family
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Get the address
comment|//------------------------------------------------------------------
name|std
operator|::
name|string
name|GetIPAddress
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Get the port if the socket address for the family has a port
comment|//------------------------------------------------------------------
name|uint16_t
name|GetPort
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Set the port if the socket address for the family has a port.
comment|// The family must be set correctly prior to calling this function.
comment|//------------------------------------------------------------------
name|bool
name|SetPort
parameter_list|(
name|uint16_t
name|port
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Set the socket address according to the first match from a call
comment|// to getaddrinfo() (or equivalent functions for systems that don't
comment|// have getaddrinfo(). If "addr_info_ptr" is not NULL, it will get
comment|// filled in with the match that was used to populate this socket
comment|// address.
comment|//------------------------------------------------------------------
name|bool
name|getaddrinfo
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
comment|// Hostname ("foo.bar.com" or "foo" or IP
comment|// address string ("123.234.12.1" or
comment|// "2001:0db8:85a3:0000:0000:8a2e:0370:7334")
specifier|const
name|char
modifier|*
name|service
parameter_list|,
comment|// Protocol name ("tcp", "http", etc) or a
comment|// raw port number string ("81")
name|int
name|ai_family
init|=
name|PF_UNSPEC
parameter_list|,
name|int
name|ai_socktype
init|=
literal|0
parameter_list|,
name|int
name|ai_protocol
init|=
literal|0
parameter_list|,
name|int
name|ai_flags
init|=
literal|0
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Quick way to set the SocketAddress to localhost given the family.
comment|// Returns true if successful, false if "family" doesn't support
comment|// localhost or if "family" is not supported by this class.
comment|//------------------------------------------------------------------
name|bool
name|SetToLocalhost
parameter_list|(
name|sa_family_t
name|family
parameter_list|,
name|uint16_t
name|port
parameter_list|)
function_decl|;
name|bool
name|SetToAnyAddress
parameter_list|(
name|sa_family_t
name|family
parameter_list|,
name|uint16_t
name|port
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Returns true if there is a valid socket address in this object.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Returns true if the socket is INADDR_ANY
comment|//------------------------------------------------------------------
name|bool
name|IsAnyAddr
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Direct access to all of the sockaddr structures
comment|//------------------------------------------------------------------
name|struct
name|sockaddr
modifier|&
name|sockaddr
function|()
block|{
return|return
name|m_socket_addr
operator|.
name|sa
return|;
block|}
specifier|const
expr|struct
name|sockaddr
operator|&
name|sockaddr
argument_list|()
specifier|const
block|{
return|return
name|m_socket_addr
operator|.
name|sa
return|;
block|}
name|struct
name|sockaddr_in
modifier|&
name|sockaddr_in
function|()
block|{
return|return
name|m_socket_addr
operator|.
name|sa_ipv4
return|;
block|}
specifier|const
expr|struct
name|sockaddr_in
operator|&
name|sockaddr_in
argument_list|()
specifier|const
block|{
return|return
name|m_socket_addr
operator|.
name|sa_ipv4
return|;
block|}
name|struct
name|sockaddr_in6
modifier|&
name|sockaddr_in6
function|()
block|{
return|return
name|m_socket_addr
operator|.
name|sa_ipv6
return|;
block|}
specifier|const
expr|struct
name|sockaddr_in6
operator|&
name|sockaddr_in6
argument_list|()
specifier|const
block|{
return|return
name|m_socket_addr
operator|.
name|sa_ipv6
return|;
block|}
name|struct
name|sockaddr_storage
modifier|&
name|sockaddr_storage
function|()
block|{
return|return
name|m_socket_addr
operator|.
name|sa_storage
return|;
block|}
specifier|const
expr|struct
name|sockaddr_storage
operator|&
name|sockaddr_storage
argument_list|()
specifier|const
block|{
return|return
name|m_socket_addr
operator|.
name|sa_storage
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Conversion operators to allow getting the contents of this class
comment|// as a pointer to the appropriate structure. This allows an instance
comment|// of this class to be used in calls that take one of the sockaddr
comment|// structure variants without having to manually use the correct
comment|// accessor function.
comment|//------------------------------------------------------------------
name|operator
name|struct
name|sockaddr
modifier|*
function|()
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa
return|;
block|}
name|operator
specifier|const
expr|struct
name|sockaddr
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa
return|;
block|}
name|operator
name|struct
name|sockaddr_in
modifier|*
function|()
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa_ipv4
return|;
block|}
name|operator
specifier|const
expr|struct
name|sockaddr_in
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa_ipv4
return|;
block|}
name|operator
name|struct
name|sockaddr_in6
modifier|*
function|()
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa_ipv6
return|;
block|}
name|operator
specifier|const
expr|struct
name|sockaddr_in6
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa_ipv6
return|;
block|}
name|operator
specifier|const
expr|struct
name|sockaddr_storage
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa_storage
return|;
block|}
name|operator
name|struct
name|sockaddr_storage
modifier|*
function|()
block|{
return|return
operator|&
name|m_socket_addr
operator|.
name|sa_storage
return|;
block|}
name|protected
label|:
typedef|typedef
union|union
name|sockaddr_tag
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|sa_ipv4
decl_stmt|;
name|struct
name|sockaddr_in6
name|sa_ipv6
decl_stmt|;
name|struct
name|sockaddr_storage
name|sa_storage
decl_stmt|;
block|}
name|sockaddr_t
typedef|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from SocketAddress can see and modify these
comment|//------------------------------------------------------------------
name|sockaddr_t
name|m_socket_addr
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_SocketAddress_h_
end_comment

end_unit

