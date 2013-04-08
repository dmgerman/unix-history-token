begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---------------------------- system_error ------------------*- C++ -*-===//
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
comment|// This was lifted from libc++ and modified for C++03. This is called
end_comment

begin_comment
comment|// system_error even though it does not define that class because that's what
end_comment

begin_comment
comment|// it's called in C++0x. We don't define system_error because it is only used
end_comment

begin_comment
comment|// for exception handling, which we don't use in LLVM.
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
name|LLVM_SUPPORT_SYSTEM_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SYSTEM_ERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_comment
comment|/*     system_error synopsis  namespace std {  class error_category { public:     virtual ~error_category();      error_category(const error_category&) = delete;     error_category& operator=(const error_category&) = delete;      virtual const char* name() const = 0;     virtual error_condition default_error_condition(int ev) const;     virtual bool equivalent(int code, const error_condition& condition) const;     virtual bool equivalent(const error_code& code, int condition) const;     virtual std::string message(int ev) const = 0;      bool operator==(const error_category& rhs) const;     bool operator!=(const error_category& rhs) const;     bool operator<(const error_category& rhs) const; };  const error_category& generic_category(); const error_category& system_category();  template<class T> struct is_error_code_enum     : public false_type {};  template<class T> struct is_error_condition_enum     : public false_type {};  class error_code { public:     // constructors:     error_code();     error_code(int val, const error_category& cat);     template<class ErrorCodeEnum>         error_code(ErrorCodeEnum e);      // modifiers:     void assign(int val, const error_category& cat);     template<class ErrorCodeEnum>         error_code& operator=(ErrorCodeEnum e);     void clear();      // observers:     int value() const;     const error_category& category() const;     error_condition default_error_condition() const;     std::string message() const;     explicit operator bool() const; };  // non-member functions: bool operator<(const error_code& lhs, const error_code& rhs); template<class charT, class traits>     basic_ostream<charT,traits>&     operator<<(basic_ostream<charT,traits>& os, const error_code& ec);  class error_condition { public:     // constructors:     error_condition();     error_condition(int val, const error_category& cat);     template<class ErrorConditionEnum>         error_condition(ErrorConditionEnum e);      // modifiers:     void assign(int val, const error_category& cat);     template<class ErrorConditionEnum>         error_condition& operator=(ErrorConditionEnum e);     void clear();      // observers:     int value() const;     const error_category& category() const;     std::string message() const;     explicit operator bool() const; };  bool operator<(const error_condition& lhs, const error_condition& rhs);  class system_error     : public runtime_error { public:     system_error(error_code ec, const std::string& what_arg);     system_error(error_code ec, const char* what_arg);     system_error(error_code ec);     system_error(int ev, const error_category& ecat, const std::string& what_arg);     system_error(int ev, const error_category& ecat, const char* what_arg);     system_error(int ev, const error_category& ecat);      const error_code& code() const throw();     const char* what() const throw(); };  enum class errc {     address_family_not_supported,       // EAFNOSUPPORT     address_in_use,                     // EADDRINUSE     address_not_available,              // EADDRNOTAVAIL     already_connected,                  // EISCONN     argument_list_too_long,             // E2BIG     argument_out_of_domain,             // EDOM     bad_address,                        // EFAULT     bad_file_descriptor,                // EBADF     bad_message,                        // EBADMSG     broken_pipe,                        // EPIPE     connection_aborted,                 // ECONNABORTED     connection_already_in_progress,     // EALREADY     connection_refused,                 // ECONNREFUSED     connection_reset,                   // ECONNRESET     cross_device_link,                  // EXDEV     destination_address_required,       // EDESTADDRREQ     device_or_resource_busy,            // EBUSY     directory_not_empty,                // ENOTEMPTY     executable_format_error,            // ENOEXEC     file_exists,                        // EEXIST     file_too_large,                     // EFBIG     filename_too_long,                  // ENAMETOOLONG     function_not_supported,             // ENOSYS     host_unreachable,                   // EHOSTUNREACH     identifier_removed,                 // EIDRM     illegal_byte_sequence,              // EILSEQ     inappropriate_io_control_operation, // ENOTTY     interrupted,                        // EINTR     invalid_argument,                   // EINVAL     invalid_seek,                       // ESPIPE     io_error,                           // EIO     is_a_directory,                     // EISDIR     message_size,                       // EMSGSIZE     network_down,                       // ENETDOWN     network_reset,                      // ENETRESET     network_unreachable,                // ENETUNREACH     no_buffer_space,                    // ENOBUFS     no_child_process,                   // ECHILD     no_link,                            // ENOLINK     no_lock_available,                  // ENOLCK     no_message_available,               // ENODATA     no_message,                         // ENOMSG     no_protocol_option,                 // ENOPROTOOPT     no_space_on_device,                 // ENOSPC     no_stream_resources,                // ENOSR     no_such_device_or_address,          // ENXIO     no_such_device,                     // ENODEV     no_such_file_or_directory,          // ENOENT     no_such_process,                    // ESRCH     not_a_directory,                    // ENOTDIR     not_a_socket,                       // ENOTSOCK     not_a_stream,                       // ENOSTR     not_connected,                      // ENOTCONN     not_enough_memory,                  // ENOMEM     not_supported,                      // ENOTSUP     operation_canceled,                 // ECANCELED     operation_in_progress,              // EINPROGRESS     operation_not_permitted,            // EPERM     operation_not_supported,            // EOPNOTSUPP     operation_would_block,              // EWOULDBLOCK     owner_dead,                         // EOWNERDEAD     permission_denied,                  // EACCES     protocol_error,                     // EPROTO     protocol_not_supported,             // EPROTONOSUPPORT     read_only_file_system,              // EROFS     resource_deadlock_would_occur,      // EDEADLK     resource_unavailable_try_again,     // EAGAIN     result_out_of_range,                // ERANGE     state_not_recoverable,              // ENOTRECOVERABLE     stream_timeout,                     // ETIME     text_file_busy,                     // ETXTBSY     timed_out,                          // ETIMEDOUT     too_many_files_open_in_system,      // ENFILE     too_many_files_open,                // EMFILE     too_many_links,                     // EMLINK     too_many_symbolic_link_levels,      // ELOOP     value_too_large,                    // EOVERFLOW     wrong_protocol_type                 // EPROTOTYPE };  template<> struct is_error_condition_enum<errc> : true_type { }  error_code make_error_code(errc e); error_condition make_error_condition(errc e);  // Comparison operators: bool operator==(const error_code& lhs, const error_code& rhs); bool operator==(const error_code& lhs, const error_condition& rhs); bool operator==(const error_condition& lhs, const error_code& rhs); bool operator==(const error_condition& lhs, const error_condition& rhs); bool operator!=(const error_code& lhs, const error_code& rhs); bool operator!=(const error_code& lhs, const error_condition& rhs); bool operator!=(const error_condition& lhs, const error_code& rhs); bool operator!=(const error_condition& lhs, const error_condition& rhs);  template<> struct hash<std::error_code>;  }  // std  */
end_comment

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<cerrno>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// This must be here instead of a .inc file because it is used in the definition
end_comment

begin_comment
comment|// of the enum values below.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LLVM_ON_WIN32
end_ifdef

begin_comment
comment|// The following numbers were taken from VS2010.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAFNOSUPPORT
end_ifndef

begin_define
define|#
directive|define
name|EAFNOSUPPORT
value|102
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EADDRINUSE
end_ifndef

begin_define
define|#
directive|define
name|EADDRINUSE
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EADDRNOTAVAIL
end_ifndef

begin_define
define|#
directive|define
name|EADDRNOTAVAIL
value|101
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EISCONN
end_ifndef

begin_define
define|#
directive|define
name|EISCONN
value|113
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|E2BIG
end_ifndef

begin_define
define|#
directive|define
name|E2BIG
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EDOM
end_ifndef

begin_define
define|#
directive|define
name|EDOM
value|33
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EFAULT
end_ifndef

begin_define
define|#
directive|define
name|EFAULT
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EBADF
end_ifndef

begin_define
define|#
directive|define
name|EBADF
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EBADMSG
end_ifndef

begin_define
define|#
directive|define
name|EBADMSG
value|104
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPIPE
end_ifndef

begin_define
define|#
directive|define
name|EPIPE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECONNABORTED
end_ifndef

begin_define
define|#
directive|define
name|ECONNABORTED
value|106
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EALREADY
end_ifndef

begin_define
define|#
directive|define
name|EALREADY
value|103
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECONNREFUSED
end_ifndef

begin_define
define|#
directive|define
name|ECONNREFUSED
value|107
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECONNRESET
end_ifndef

begin_define
define|#
directive|define
name|ECONNRESET
value|108
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXDEV
end_ifndef

begin_define
define|#
directive|define
name|EXDEV
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EDESTADDRREQ
end_ifndef

begin_define
define|#
directive|define
name|EDESTADDRREQ
value|109
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EBUSY
end_ifndef

begin_define
define|#
directive|define
name|EBUSY
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTEMPTY
end_ifndef

begin_define
define|#
directive|define
name|ENOTEMPTY
value|41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOEXEC
end_ifndef

begin_define
define|#
directive|define
name|ENOEXEC
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EEXIST
end_ifndef

begin_define
define|#
directive|define
name|EEXIST
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EFBIG
end_ifndef

begin_define
define|#
directive|define
name|EFBIG
value|27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENAMETOOLONG
end_ifndef

begin_define
define|#
directive|define
name|ENAMETOOLONG
value|38
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSYS
end_ifndef

begin_define
define|#
directive|define
name|ENOSYS
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EHOSTUNREACH
end_ifndef

begin_define
define|#
directive|define
name|EHOSTUNREACH
value|110
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EIDRM
end_ifndef

begin_define
define|#
directive|define
name|EIDRM
value|111
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EILSEQ
end_ifndef

begin_define
define|#
directive|define
name|EILSEQ
value|42
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTTY
end_ifndef

begin_define
define|#
directive|define
name|ENOTTY
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EINTR
end_ifndef

begin_define
define|#
directive|define
name|EINTR
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EINVAL
end_ifndef

begin_define
define|#
directive|define
name|EINVAL
value|22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ESPIPE
end_ifndef

begin_define
define|#
directive|define
name|ESPIPE
value|29
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EIO
end_ifndef

begin_define
define|#
directive|define
name|EIO
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EISDIR
end_ifndef

begin_define
define|#
directive|define
name|EISDIR
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EMSGSIZE
end_ifndef

begin_define
define|#
directive|define
name|EMSGSIZE
value|115
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENETDOWN
end_ifndef

begin_define
define|#
directive|define
name|ENETDOWN
value|116
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENETRESET
end_ifndef

begin_define
define|#
directive|define
name|ENETRESET
value|117
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENETUNREACH
end_ifndef

begin_define
define|#
directive|define
name|ENETUNREACH
value|118
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOBUFS
end_ifndef

begin_define
define|#
directive|define
name|ENOBUFS
value|119
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECHILD
end_ifndef

begin_define
define|#
directive|define
name|ECHILD
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOLINK
end_ifndef

begin_define
define|#
directive|define
name|ENOLINK
value|121
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOLCK
end_ifndef

begin_define
define|#
directive|define
name|ENOLCK
value|39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENODATA
end_ifndef

begin_define
define|#
directive|define
name|ENODATA
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOMSG
end_ifndef

begin_define
define|#
directive|define
name|ENOMSG
value|122
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOPROTOOPT
end_ifndef

begin_define
define|#
directive|define
name|ENOPROTOOPT
value|123
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSPC
end_ifndef

begin_define
define|#
directive|define
name|ENOSPC
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSR
end_ifndef

begin_define
define|#
directive|define
name|ENOSR
value|124
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENXIO
end_ifndef

begin_define
define|#
directive|define
name|ENXIO
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENODEV
end_ifndef

begin_define
define|#
directive|define
name|ENODEV
value|19
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOENT
end_ifndef

begin_define
define|#
directive|define
name|ENOENT
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ESRCH
end_ifndef

begin_define
define|#
directive|define
name|ESRCH
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTDIR
end_ifndef

begin_define
define|#
directive|define
name|ENOTDIR
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTSOCK
end_ifndef

begin_define
define|#
directive|define
name|ENOTSOCK
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSTR
end_ifndef

begin_define
define|#
directive|define
name|ENOSTR
value|125
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTCONN
end_ifndef

begin_define
define|#
directive|define
name|ENOTCONN
value|126
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOMEM
end_ifndef

begin_define
define|#
directive|define
name|ENOMEM
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTSUP
end_ifndef

begin_define
define|#
directive|define
name|ENOTSUP
value|129
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECANCELED
end_ifndef

begin_define
define|#
directive|define
name|ECANCELED
value|105
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EINPROGRESS
end_ifndef

begin_define
define|#
directive|define
name|EINPROGRESS
value|112
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPERM
end_ifndef

begin_define
define|#
directive|define
name|EPERM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOPNOTSUPP
end_ifndef

begin_define
define|#
directive|define
name|EOPNOTSUPP
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EWOULDBLOCK
end_ifndef

begin_define
define|#
directive|define
name|EWOULDBLOCK
value|140
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOWNERDEAD
end_ifndef

begin_define
define|#
directive|define
name|EOWNERDEAD
value|133
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EACCES
end_ifndef

begin_define
define|#
directive|define
name|EACCES
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPROTO
end_ifndef

begin_define
define|#
directive|define
name|EPROTO
value|134
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPROTONOSUPPORT
end_ifndef

begin_define
define|#
directive|define
name|EPROTONOSUPPORT
value|135
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EROFS
end_ifndef

begin_define
define|#
directive|define
name|EROFS
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EDEADLK
end_ifndef

begin_define
define|#
directive|define
name|EDEADLK
value|36
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EAGAIN
end_ifndef

begin_define
define|#
directive|define
name|EAGAIN
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ERANGE
end_ifndef

begin_define
define|#
directive|define
name|ERANGE
value|34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTRECOVERABLE
end_ifndef

begin_define
define|#
directive|define
name|ENOTRECOVERABLE
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETIME
end_ifndef

begin_define
define|#
directive|define
name|ETIME
value|137
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETXTBSY
end_ifndef

begin_define
define|#
directive|define
name|ETXTBSY
value|139
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETIMEDOUT
end_ifndef

begin_define
define|#
directive|define
name|ETIMEDOUT
value|138
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENFILE
end_ifndef

begin_define
define|#
directive|define
name|ENFILE
value|23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EMFILE
end_ifndef

begin_define
define|#
directive|define
name|EMFILE
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EMLINK
end_ifndef

begin_define
define|#
directive|define
name|EMLINK
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ELOOP
end_ifndef

begin_define
define|#
directive|define
name|ELOOP
value|114
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|EOVERFLOW
value|132
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EPROTOTYPE
end_ifndef

begin_define
define|#
directive|define
name|EPROTOTYPE
value|136
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// is_error_code_enum
name|template
operator|<
name|class
name|Tp
operator|>
expr|struct
name|is_error_code_enum
operator|:
name|public
name|false_type
block|{}
expr_stmt|;
comment|// is_error_condition_enum
name|template
operator|<
name|class
name|Tp
operator|>
expr|struct
name|is_error_condition_enum
operator|:
name|public
name|false_type
block|{}
expr_stmt|;
comment|// Some error codes are not present on all platforms, so we provide equivalents
comment|// for them:
comment|//enum class errc
struct|struct
name|errc
block|{
enum|enum
name|_
block|{
name|success
init|=
literal|0
block|,
name|address_family_not_supported
init|=
name|EAFNOSUPPORT
block|,
name|address_in_use
init|=
name|EADDRINUSE
block|,
name|address_not_available
init|=
name|EADDRNOTAVAIL
block|,
name|already_connected
init|=
name|EISCONN
block|,
name|argument_list_too_long
init|=
name|E2BIG
block|,
name|argument_out_of_domain
init|=
name|EDOM
block|,
name|bad_address
init|=
name|EFAULT
block|,
name|bad_file_descriptor
init|=
name|EBADF
block|,
ifdef|#
directive|ifdef
name|EBADMSG
name|bad_message
init|=
name|EBADMSG
block|,
else|#
directive|else
name|bad_message
init|=
name|EINVAL
block|,
endif|#
directive|endif
name|broken_pipe
init|=
name|EPIPE
block|,
name|connection_aborted
init|=
name|ECONNABORTED
block|,
name|connection_already_in_progress
init|=
name|EALREADY
block|,
name|connection_refused
init|=
name|ECONNREFUSED
block|,
name|connection_reset
init|=
name|ECONNRESET
block|,
name|cross_device_link
init|=
name|EXDEV
block|,
name|destination_address_required
init|=
name|EDESTADDRREQ
block|,
name|device_or_resource_busy
init|=
name|EBUSY
block|,
name|directory_not_empty
init|=
name|ENOTEMPTY
block|,
name|executable_format_error
init|=
name|ENOEXEC
block|,
name|file_exists
init|=
name|EEXIST
block|,
name|file_too_large
init|=
name|EFBIG
block|,
name|filename_too_long
init|=
name|ENAMETOOLONG
block|,
name|function_not_supported
init|=
name|ENOSYS
block|,
name|host_unreachable
init|=
name|EHOSTUNREACH
block|,
name|identifier_removed
init|=
name|EIDRM
block|,
name|illegal_byte_sequence
init|=
name|EILSEQ
block|,
name|inappropriate_io_control_operation
init|=
name|ENOTTY
block|,
name|interrupted
init|=
name|EINTR
block|,
name|invalid_argument
init|=
name|EINVAL
block|,
name|invalid_seek
init|=
name|ESPIPE
block|,
name|io_error
init|=
name|EIO
block|,
name|is_a_directory
init|=
name|EISDIR
block|,
name|message_size
init|=
name|EMSGSIZE
block|,
name|network_down
init|=
name|ENETDOWN
block|,
name|network_reset
init|=
name|ENETRESET
block|,
name|network_unreachable
init|=
name|ENETUNREACH
block|,
name|no_buffer_space
init|=
name|ENOBUFS
block|,
name|no_child_process
init|=
name|ECHILD
block|,
ifdef|#
directive|ifdef
name|ENOLINK
name|no_link
init|=
name|ENOLINK
block|,
else|#
directive|else
name|no_link
init|=
name|EINVAL
block|,
endif|#
directive|endif
name|no_lock_available
init|=
name|ENOLCK
block|,
ifdef|#
directive|ifdef
name|ENODATA
name|no_message_available
init|=
name|ENODATA
block|,
else|#
directive|else
name|no_message_available
init|=
name|ENOMSG
block|,
endif|#
directive|endif
name|no_message
init|=
name|ENOMSG
block|,
name|no_protocol_option
init|=
name|ENOPROTOOPT
block|,
name|no_space_on_device
init|=
name|ENOSPC
block|,
ifdef|#
directive|ifdef
name|ENOSR
name|no_stream_resources
init|=
name|ENOSR
block|,
else|#
directive|else
name|no_stream_resources
init|=
name|ENOMEM
block|,
endif|#
directive|endif
name|no_such_device_or_address
init|=
name|ENXIO
block|,
name|no_such_device
init|=
name|ENODEV
block|,
name|no_such_file_or_directory
init|=
name|ENOENT
block|,
name|no_such_process
init|=
name|ESRCH
block|,
name|not_a_directory
init|=
name|ENOTDIR
block|,
name|not_a_socket
init|=
name|ENOTSOCK
block|,
ifdef|#
directive|ifdef
name|ENOSTR
name|not_a_stream
init|=
name|ENOSTR
block|,
else|#
directive|else
name|not_a_stream
init|=
name|EINVAL
block|,
endif|#
directive|endif
name|not_connected
init|=
name|ENOTCONN
block|,
name|not_enough_memory
init|=
name|ENOMEM
block|,
name|not_supported
init|=
name|ENOTSUP
block|,
ifdef|#
directive|ifdef
name|ECANCELED
name|operation_canceled
init|=
name|ECANCELED
block|,
else|#
directive|else
name|operation_canceled
init|=
name|EINVAL
block|,
endif|#
directive|endif
name|operation_in_progress
init|=
name|EINPROGRESS
block|,
name|operation_not_permitted
init|=
name|EPERM
block|,
name|operation_not_supported
init|=
name|EOPNOTSUPP
block|,
name|operation_would_block
init|=
name|EWOULDBLOCK
block|,
ifdef|#
directive|ifdef
name|EOWNERDEAD
name|owner_dead
init|=
name|EOWNERDEAD
block|,
else|#
directive|else
name|owner_dead
init|=
name|EINVAL
block|,
endif|#
directive|endif
name|permission_denied
init|=
name|EACCES
block|,
ifdef|#
directive|ifdef
name|EPROTO
name|protocol_error
init|=
name|EPROTO
block|,
else|#
directive|else
name|protocol_error
init|=
name|EINVAL
block|,
endif|#
directive|endif
name|protocol_not_supported
init|=
name|EPROTONOSUPPORT
block|,
name|read_only_file_system
init|=
name|EROFS
block|,
name|resource_deadlock_would_occur
init|=
name|EDEADLK
block|,
name|resource_unavailable_try_again
init|=
name|EAGAIN
block|,
name|result_out_of_range
init|=
name|ERANGE
block|,
ifdef|#
directive|ifdef
name|ENOTRECOVERABLE
name|state_not_recoverable
init|=
name|ENOTRECOVERABLE
block|,
else|#
directive|else
name|state_not_recoverable
init|=
name|EINVAL
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ETIME
name|stream_timeout
init|=
name|ETIME
block|,
else|#
directive|else
name|stream_timeout
init|=
name|ETIMEDOUT
block|,
endif|#
directive|endif
name|text_file_busy
init|=
name|ETXTBSY
block|,
name|timed_out
init|=
name|ETIMEDOUT
block|,
name|too_many_files_open_in_system
init|=
name|ENFILE
block|,
name|too_many_files_open
init|=
name|EMFILE
block|,
name|too_many_links
init|=
name|EMLINK
block|,
name|too_many_symbolic_link_levels
init|=
name|ELOOP
block|,
name|value_too_large
init|=
name|EOVERFLOW
block|,
name|wrong_protocol_type
init|=
name|EPROTOTYPE
block|}
enum|;
name|_
name|v_
decl_stmt|;
name|errc
argument_list|(
argument|_ v
argument_list|)
block|:
name|v_
argument_list|(
argument|v
argument_list|)
block|{}
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|v_
return|;
block|}
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|is_error_condition_enum
operator|<
name|errc
operator|>
operator|:
name|true_type
block|{ }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|is_error_condition_enum
operator|<
name|errc
operator|::
name|_
operator|>
operator|:
name|true_type
block|{ }
expr_stmt|;
name|class
name|error_condition
decl_stmt|;
name|class
name|error_code
decl_stmt|;
comment|// class error_category
name|class
name|_do_message
decl_stmt|;
name|class
name|error_category
block|{
name|public
label|:
name|virtual
operator|~
name|error_category
argument_list|()
expr_stmt|;
name|private
label|:
name|error_category
argument_list|()
expr_stmt|;
name|error_category
argument_list|(
argument|const error_category&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|error_category
modifier|&
name|operator
init|=
operator|(
specifier|const
name|error_category
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
name|virtual
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|error_condition
name|default_error_condition
argument_list|(
name|int
name|_ev
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|equivalent
argument_list|(
name|int
name|_code
argument_list|,
specifier|const
name|error_condition
operator|&
name|_condition
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|equivalent
argument_list|(
specifier|const
name|error_code
operator|&
name|_code
argument_list|,
name|int
name|_condition
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|std
operator|::
name|string
name|message
argument_list|(
argument|int _ev
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|error_category
operator|&
name|_rhs
operator|)
specifier|const
block|{
return|return
name|this
operator|==
operator|&
name|_rhs
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|error_category
operator|&
name|_rhs
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|_rhs
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|error_category
operator|&
name|_rhs
operator|)
specifier|const
block|{
return|return
name|this
operator|<
operator|&
name|_rhs
return|;
block|}
name|friend
name|class
name|_do_message
decl_stmt|;
block|}
empty_stmt|;
name|class
name|_do_message
range|:
name|public
name|error_category
block|{
name|public
operator|:
name|virtual
name|std
operator|::
name|string
name|message
argument_list|(
argument|int ev
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|; }
decl_stmt|;
specifier|const
name|error_category
modifier|&
name|generic_category
parameter_list|()
function_decl|;
specifier|const
name|error_category
modifier|&
name|system_category
parameter_list|()
function_decl|;
comment|/// Get the error_category used for errno values from POSIX functions. This is
comment|/// the same as the system_category on POSIX systems, but is the same as the
comment|/// generic_category on Windows.
specifier|const
name|error_category
modifier|&
name|posix_category
parameter_list|()
function_decl|;
name|class
name|error_condition
block|{
name|int
name|_val_
decl_stmt|;
specifier|const
name|error_category
modifier|*
name|_cat_
decl_stmt|;
name|public
label|:
name|error_condition
argument_list|()
operator|:
name|_val_
argument_list|(
literal|0
argument_list|)
operator|,
name|_cat_
argument_list|(
argument|&generic_category()
argument_list|)
block|{}
name|error_condition
argument_list|(
argument|int _val
argument_list|,
argument|const error_category& _cat
argument_list|)
operator|:
name|_val_
argument_list|(
name|_val
argument_list|)
operator|,
name|_cat_
argument_list|(
argument|&_cat
argument_list|)
block|{}
name|template
operator|<
name|class
name|E
operator|>
name|error_condition
argument_list|(
argument|E _e
argument_list|,
argument|typename enable_if_c<                           is_error_condition_enum<E>::value>::type* =
literal|0
argument_list|)
block|{
operator|*
name|this
operator|=
name|make_error_condition
argument_list|(
name|_e
argument_list|)
block|;}
name|void
name|assign
argument_list|(
argument|int _val
argument_list|,
argument|const error_category& _cat
argument_list|)
block|{
name|_val_
operator|=
name|_val
block|;
name|_cat_
operator|=
operator|&
name|_cat
block|;   }
name|template
operator|<
name|class
name|E
operator|>
name|typename
name|enable_if_c
operator|<
name|is_error_condition_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|,
name|error_condition
operator|&
operator|>
operator|::
name|type
name|operator
operator|=
operator|(
name|E
name|_e
operator|)
block|{
operator|*
name|this
operator|=
name|make_error_condition
argument_list|(
name|_e
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|_val_
operator|=
literal|0
expr_stmt|;
name|_cat_
operator|=
operator|&
name|generic_category
argument_list|()
expr_stmt|;
block|}
name|int
name|value
argument_list|()
specifier|const
block|{
return|return
name|_val_
return|;
block|}
specifier|const
name|error_category
operator|&
name|category
argument_list|()
specifier|const
block|{
return|return
operator|*
name|_cat_
return|;
block|}
name|std
operator|::
name|string
name|message
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|unspecified_bool_type
function_decl|)
parameter_list|()
function_decl|;
specifier|static
name|void
name|unspecified_bool_true
parameter_list|()
block|{}
name|operator
name|unspecified_bool_type
argument_list|()
specifier|const
block|{
comment|// true if error
return|return
name|_val_
operator|==
literal|0
operator|?
literal|0
operator|:
name|unspecified_bool_true
return|;
block|}
block|}
empty_stmt|;
specifier|inline
name|error_condition
name|make_error_condition
parameter_list|(
name|errc
name|_e
parameter_list|)
block|{
return|return
name|error_condition
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|_e
operator|)
argument_list|,
name|generic_category
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|error_condition
operator|&
name|_x
operator|,
specifier|const
name|error_condition
operator|&
name|_y
operator|)
block|{
return|return
name|_x
operator|.
name|category
argument_list|()
operator|<
name|_y
operator|.
name|category
argument_list|()
operator|||
operator|(
name|_x
operator|.
name|category
argument_list|()
operator|==
name|_y
operator|.
name|category
argument_list|()
operator|&&
name|_x
operator|.
name|value
argument_list|()
operator|<
name|_y
operator|.
name|value
argument_list|()
operator|)
return|;
block|}
comment|// error_code
name|class
name|error_code
block|{
name|int
name|_val_
decl_stmt|;
specifier|const
name|error_category
modifier|*
name|_cat_
decl_stmt|;
name|public
label|:
name|error_code
argument_list|()
operator|:
name|_val_
argument_list|(
literal|0
argument_list|)
operator|,
name|_cat_
argument_list|(
argument|&system_category()
argument_list|)
block|{}
specifier|static
name|error_code
name|success
argument_list|()
block|{
return|return
name|error_code
argument_list|()
return|;
block|}
name|error_code
argument_list|(
argument|int _val
argument_list|,
argument|const error_category& _cat
argument_list|)
block|:
name|_val_
argument_list|(
name|_val
argument_list|)
operator|,
name|_cat_
argument_list|(
argument|&_cat
argument_list|)
block|{}
name|template
operator|<
name|class
name|E
operator|>
name|error_code
argument_list|(
argument|E _e
argument_list|,
argument|typename enable_if_c<                      is_error_code_enum<E>::value>::type* =
literal|0
argument_list|)
block|{
operator|*
name|this
operator|=
name|make_error_code
argument_list|(
name|_e
argument_list|)
block|;   }
name|void
name|assign
argument_list|(
argument|int _val
argument_list|,
argument|const error_category& _cat
argument_list|)
block|{
name|_val_
operator|=
name|_val
block|;
name|_cat_
operator|=
operator|&
name|_cat
block|;   }
name|template
operator|<
name|class
name|E
operator|>
name|typename
name|enable_if_c
operator|<
name|is_error_code_enum
operator|<
name|E
operator|>
operator|::
name|value
operator|,
name|error_code
operator|&
operator|>
operator|::
name|type
name|operator
operator|=
operator|(
name|E
name|_e
operator|)
block|{
operator|*
name|this
operator|=
name|make_error_code
argument_list|(
name|_e
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|_val_
operator|=
literal|0
expr_stmt|;
name|_cat_
operator|=
operator|&
name|system_category
argument_list|()
expr_stmt|;
block|}
name|int
name|value
argument_list|()
specifier|const
block|{
return|return
name|_val_
return|;
block|}
specifier|const
name|error_category
operator|&
name|category
argument_list|()
specifier|const
block|{
return|return
operator|*
name|_cat_
return|;
block|}
name|error_condition
name|default_error_condition
argument_list|()
specifier|const
block|{
return|return
name|_cat_
operator|->
name|default_error_condition
argument_list|(
name|_val_
argument_list|)
return|;
block|}
name|std
operator|::
name|string
name|message
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|unspecified_bool_type
function_decl|)
parameter_list|()
function_decl|;
specifier|static
name|void
name|unspecified_bool_true
parameter_list|()
block|{}
name|operator
name|unspecified_bool_type
argument_list|()
specifier|const
block|{
comment|// true if error
return|return
name|_val_
operator|==
literal|0
operator|?
literal|0
operator|:
name|unspecified_bool_true
return|;
block|}
block|}
empty_stmt|;
specifier|inline
name|error_code
name|make_error_code
parameter_list|(
name|errc
name|_e
parameter_list|)
block|{
return|return
name|error_code
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|_e
operator|)
argument_list|,
name|generic_category
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|error_code
operator|&
name|_x
operator|,
specifier|const
name|error_code
operator|&
name|_y
operator|)
block|{
return|return
name|_x
operator|.
name|category
argument_list|()
operator|<
name|_y
operator|.
name|category
argument_list|()
operator|||
operator|(
name|_x
operator|.
name|category
argument_list|()
operator|==
name|_y
operator|.
name|category
argument_list|()
operator|&&
name|_x
operator|.
name|value
argument_list|()
operator|<
name|_y
operator|.
name|value
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|error_code
operator|&
name|_x
operator|,
specifier|const
name|error_code
operator|&
name|_y
operator|)
block|{
return|return
name|_x
operator|.
name|category
argument_list|()
operator|==
name|_y
operator|.
name|category
argument_list|()
operator|&&
name|_x
operator|.
name|value
argument_list|()
operator|==
name|_y
operator|.
name|value
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|error_code
operator|&
name|_x
operator|,
specifier|const
name|error_condition
operator|&
name|_y
operator|)
block|{
return|return
name|_x
operator|.
name|category
argument_list|()
operator|.
name|equivalent
argument_list|(
name|_x
operator|.
name|value
argument_list|()
argument_list|,
name|_y
argument_list|)
operator|||
name|_y
operator|.
name|category
argument_list|()
operator|.
name|equivalent
argument_list|(
name|_x
argument_list|,
name|_y
operator|.
name|value
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|error_condition
operator|&
name|_x
operator|,
specifier|const
name|error_code
operator|&
name|_y
operator|)
block|{
return|return
name|_y
operator|==
name|_x
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|error_condition
operator|&
name|_x
operator|,
specifier|const
name|error_condition
operator|&
name|_y
operator|)
block|{
return|return
name|_x
operator|.
name|category
argument_list|()
operator|==
name|_y
operator|.
name|category
argument_list|()
operator|&&
name|_x
operator|.
name|value
argument_list|()
operator|==
name|_y
operator|.
name|value
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|error_code
operator|&
name|_x
operator|,
specifier|const
name|error_code
operator|&
name|_y
operator|)
block|{
return|return
operator|!
operator|(
name|_x
operator|==
name|_y
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|error_code
operator|&
name|_x
operator|,
specifier|const
name|error_condition
operator|&
name|_y
operator|)
block|{
return|return
operator|!
operator|(
name|_x
operator|==
name|_y
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|error_condition
operator|&
name|_x
operator|,
specifier|const
name|error_code
operator|&
name|_y
operator|)
block|{
return|return
operator|!
operator|(
name|_x
operator|==
name|_y
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|error_condition
operator|&
name|_x
operator|,
specifier|const
name|error_condition
operator|&
name|_y
operator|)
block|{
return|return
operator|!
operator|(
name|_x
operator|==
name|_y
operator|)
return|;
block|}
comment|// Windows errors.
comment|//  To construct an error_code after an API error:
comment|//
comment|//      error_code( ::GetLastError(), system_category() )
struct|struct
name|windows_error
block|{
enum|enum
name|_
block|{
name|success
init|=
literal|0
block|,
comment|// These names and values are based on Windows WinError.h
comment|// This is not a complete list. Add to this list if you need to explicitly
comment|// check for it.
name|invalid_function
init|=
literal|1
block|,
comment|// ERROR_INVALID_FUNCTION,
name|file_not_found
init|=
literal|2
block|,
comment|// ERROR_FILE_NOT_FOUND,
name|path_not_found
init|=
literal|3
block|,
comment|// ERROR_PATH_NOT_FOUND,
name|too_many_open_files
init|=
literal|4
block|,
comment|// ERROR_TOO_MANY_OPEN_FILES,
name|access_denied
init|=
literal|5
block|,
comment|// ERROR_ACCESS_DENIED,
name|invalid_handle
init|=
literal|6
block|,
comment|// ERROR_INVALID_HANDLE,
name|arena_trashed
init|=
literal|7
block|,
comment|// ERROR_ARENA_TRASHED,
name|not_enough_memory
init|=
literal|8
block|,
comment|// ERROR_NOT_ENOUGH_MEMORY,
name|invalid_block
init|=
literal|9
block|,
comment|// ERROR_INVALID_BLOCK,
name|bad_environment
init|=
literal|10
block|,
comment|// ERROR_BAD_ENVIRONMENT,
name|bad_format
init|=
literal|11
block|,
comment|// ERROR_BAD_FORMAT,
name|invalid_access
init|=
literal|12
block|,
comment|// ERROR_INVALID_ACCESS,
name|outofmemory
init|=
literal|14
block|,
comment|// ERROR_OUTOFMEMORY,
name|invalid_drive
init|=
literal|15
block|,
comment|// ERROR_INVALID_DRIVE,
name|current_directory
init|=
literal|16
block|,
comment|// ERROR_CURRENT_DIRECTORY,
name|not_same_device
init|=
literal|17
block|,
comment|// ERROR_NOT_SAME_DEVICE,
name|no_more_files
init|=
literal|18
block|,
comment|// ERROR_NO_MORE_FILES,
name|write_protect
init|=
literal|19
block|,
comment|// ERROR_WRITE_PROTECT,
name|bad_unit
init|=
literal|20
block|,
comment|// ERROR_BAD_UNIT,
name|not_ready
init|=
literal|21
block|,
comment|// ERROR_NOT_READY,
name|bad_command
init|=
literal|22
block|,
comment|// ERROR_BAD_COMMAND,
name|crc
init|=
literal|23
block|,
comment|// ERROR_CRC,
name|bad_length
init|=
literal|24
block|,
comment|// ERROR_BAD_LENGTH,
name|seek
init|=
literal|25
block|,
comment|// ERROR_SEEK,
name|not_dos_disk
init|=
literal|26
block|,
comment|// ERROR_NOT_DOS_DISK,
name|sector_not_found
init|=
literal|27
block|,
comment|// ERROR_SECTOR_NOT_FOUND,
name|out_of_paper
init|=
literal|28
block|,
comment|// ERROR_OUT_OF_PAPER,
name|write_fault
init|=
literal|29
block|,
comment|// ERROR_WRITE_FAULT,
name|read_fault
init|=
literal|30
block|,
comment|// ERROR_READ_FAULT,
name|gen_failure
init|=
literal|31
block|,
comment|// ERROR_GEN_FAILURE,
name|sharing_violation
init|=
literal|32
block|,
comment|// ERROR_SHARING_VIOLATION,
name|lock_violation
init|=
literal|33
block|,
comment|// ERROR_LOCK_VIOLATION,
name|wrong_disk
init|=
literal|34
block|,
comment|// ERROR_WRONG_DISK,
name|sharing_buffer_exceeded
init|=
literal|36
block|,
comment|// ERROR_SHARING_BUFFER_EXCEEDED,
name|handle_eof
init|=
literal|38
block|,
comment|// ERROR_HANDLE_EOF,
name|handle_disk_full
init|=
literal|39
block|,
comment|// ERROR_HANDLE_DISK_FULL,
name|rem_not_list
init|=
literal|51
block|,
comment|// ERROR_REM_NOT_LIST,
name|dup_name
init|=
literal|52
block|,
comment|// ERROR_DUP_NAME,
name|bad_net_path
init|=
literal|53
block|,
comment|// ERROR_BAD_NETPATH,
name|network_busy
init|=
literal|54
block|,
comment|// ERROR_NETWORK_BUSY,
name|file_exists
init|=
literal|80
block|,
comment|// ERROR_FILE_EXISTS,
name|cannot_make
init|=
literal|82
block|,
comment|// ERROR_CANNOT_MAKE,
name|broken_pipe
init|=
literal|109
block|,
comment|// ERROR_BROKEN_PIPE,
name|open_failed
init|=
literal|110
block|,
comment|// ERROR_OPEN_FAILED,
name|buffer_overflow
init|=
literal|111
block|,
comment|// ERROR_BUFFER_OVERFLOW,
name|disk_full
init|=
literal|112
block|,
comment|// ERROR_DISK_FULL,
name|insufficient_buffer
init|=
literal|122
block|,
comment|// ERROR_INSUFFICIENT_BUFFER,
name|lock_failed
init|=
literal|167
block|,
comment|// ERROR_LOCK_FAILED,
name|busy
init|=
literal|170
block|,
comment|// ERROR_BUSY,
name|cancel_violation
init|=
literal|173
block|,
comment|// ERROR_CANCEL_VIOLATION,
name|already_exists
init|=
literal|183
comment|// ERROR_ALREADY_EXISTS
block|}
enum|;
name|_
name|v_
decl_stmt|;
name|windows_error
argument_list|(
argument|_ v
argument_list|)
block|:
name|v_
argument_list|(
argument|v
argument_list|)
block|{}
name|explicit
name|windows_error
argument_list|(
argument|int v
argument_list|)
block|:
name|v_
argument_list|(
argument|_(v)
argument_list|)
block|{}
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|v_
return|;
block|}
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|windows_error
operator|>
operator|:
name|true_type
block|{ }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|windows_error
operator|::
name|_
operator|>
operator|:
name|true_type
block|{ }
expr_stmt|;
specifier|inline
name|error_code
name|make_error_code
parameter_list|(
name|windows_error
name|e
parameter_list|)
block|{
return|return
name|error_code
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|e
operator|)
argument_list|,
name|system_category
argument_list|()
argument_list|)
return|;
block|}
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

