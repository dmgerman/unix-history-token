begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Tunala ("Tunneler with a New Zealand accent")  *  * Written by Geoff Thorpe, but endorsed/supported by noone. Please use this is  * if it's useful or informative to you, but it's only here as a scratchpad for  * ideas about how you might (or might not) program with OpenSSL. If you deploy  * this is in a mission-critical environment, and have not read, understood,  * audited, and modified this code to your satisfaction, and the result is that  * all hell breaks loose and you are looking for a new employer, then it proves  * nothing except perhaps that Darwinism is alive and well. Let's just say, *I*  * don't use this in a mission-critical environment, so it would be stupid for  * anyone to assume that it is solid and/or tested enough when even its author  * doesn't place that much trust in it. You have been warned.  *  * With thanks to Cryptographic Appliances, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TUNALA_H
end_ifndef

begin_define
define|#
directive|define
name|_TUNALA_H
end_define

begin_comment
comment|/* pull in autoconf fluff */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CONFIG_H
end_ifndef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We don't have autoconf, we have to set all of these unless a tweaked Makefile  * tells us not to ... */
end_comment

begin_comment
comment|/* headers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HAVE_SELECT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SELECT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HAVE_SOCKET
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SOCKET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HAVE_UNISTD_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HAVE_FCNTL_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HAVE_LIMITS_H
end_ifndef

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* features */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HAVE_STRSTR
end_ifndef

begin_define
define|#
directive|define
name|HAVE_STRSTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HAVE_STRTOUL
end_ifndef

begin_define
define|#
directive|define
name|HAVE_STRTOUL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SELECT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_SOCKET
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"can't build without some network basics like select() and socket()"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYSTEM_H
end_ifndef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_SYSTEM_H) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_OPENSSL
end_ifndef

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_OPENSSL) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_BUFFER
end_ifndef

begin_comment
comment|/* This is the generic "buffer" type that is used when feeding the  * state-machine. It's basically a FIFO with respect to the "adddata"&  * "takedata" type functions that operate on it. */
end_comment

begin_define
define|#
directive|define
name|MAX_DATA_SIZE
value|16384
end_define

begin_typedef
typedef|typedef
struct|struct
name|_buffer_t
block|{
name|unsigned
name|char
name|data
index|[
name|MAX_DATA_SIZE
index|]
decl_stmt|;
name|unsigned
name|int
name|used
decl_stmt|;
comment|/* Statistical values - counts the total number of bytes read in and 	 * read out (respectively) since "buffer_init()" */
name|unsigned
name|long
name|total_in
decl_stmt|,
name|total_out
decl_stmt|;
block|}
name|buffer_t
typedef|;
end_typedef

begin_comment
comment|/* Initialise a buffer structure before use */
end_comment

begin_function_decl
name|void
name|buffer_init
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cleanup a buffer structure - presently not needed, but if buffer_t is  * converted to using dynamic allocation, this would be required - so should be  * called to protect against an explosion of memory leaks later if the change is  * made. */
end_comment

begin_function_decl
name|void
name|buffer_close
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Basic functions to manipulate buffers */
end_comment

begin_function_decl
name|unsigned
name|int
name|buffer_used
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* How much data in the buffer */
end_comment

begin_function_decl
name|unsigned
name|int
name|buffer_unused
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* How much space in the buffer */
end_comment

begin_function_decl
name|int
name|buffer_full
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Boolean, is it full? */
end_comment

begin_function_decl
name|int
name|buffer_notfull
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Boolean, is it not full? */
end_comment

begin_function_decl
name|int
name|buffer_empty
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Boolean, is it empty? */
end_comment

begin_function_decl
name|int
name|buffer_notempty
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Boolean, is it not empty? */
end_comment

begin_function_decl
name|unsigned
name|long
name|buffer_total_in
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Total bytes written to buffer */
end_comment

begin_function_decl
name|unsigned
name|long
name|buffer_total_out
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Total bytes read from buffer */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Currently used only within buffer.c - better to expose only        * higher-level functions anyway */
end_comment

begin_comment
comment|/* Add data to the tail of the buffer, returns the amount that was actually  * added (so, you need to check if return value is less than size) */
end_comment

begin_comment
unit|unsigned int buffer_adddata(buffer_t *buf, const unsigned char *ptr, 		unsigned int size);
comment|/* Take data from the front of the buffer (and scroll the rest forward). If  * "ptr" is NULL, this just removes data off the front of the buffer. Return  * value is the amount actually removed (can be less than size if the buffer has  * too little data). */
end_comment

begin_comment
unit|unsigned int buffer_takedata(buffer_t *buf, unsigned char *ptr, 		unsigned int size);
comment|/* Flushes as much data as possible out of the "from" buffer into the "to"  * buffer. Return value is the amount moved. The amount moved can be restricted  * to a maximum by specifying "cap" - setting it to -1 means no limit. */
end_comment

begin_endif
unit|unsigned int buffer_tobuffer(buffer_t *to, buffer_t *from, int cap);
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_IP
end_ifndef

begin_comment
comment|/* Read or write between a file-descriptor and a buffer */
end_comment

begin_function_decl
name|int
name|buffer_from_fd
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_to_fd
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_IP) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_OPENSSL
end_ifndef

begin_comment
comment|/* Read or write between an SSL or BIO and a buffer */
end_comment

begin_function_decl
name|void
name|buffer_from_SSL
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|,
name|SSL
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_to_SSL
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|,
name|SSL
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_from_BIO
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|,
name|BIO
modifier|*
name|bio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_to_BIO
parameter_list|(
name|buffer_t
modifier|*
name|buf
parameter_list|,
name|BIO
modifier|*
name|bio
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Callbacks */
end_comment

begin_function_decl
name|void
name|cb_ssl_info
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|where
parameter_list|,
name|int
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cb_ssl_info_set_output
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Called if output should be sent too */
end_comment

begin_function_decl
name|int
name|cb_ssl_verify
parameter_list|(
name|int
name|ok
parameter_list|,
name|X509_STORE_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cb_ssl_verify_set_output
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cb_ssl_verify_set_depth
parameter_list|(
name|unsigned
name|int
name|verify_depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cb_ssl_verify_set_level
parameter_list|(
name|unsigned
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_OPENSSL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(OPENSSL_NO_BUFFER) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TUNALA
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_NO_BUFFER
end_ifdef

begin_error
error|#
directive|error
literal|"TUNALA section of tunala.h requires BUFFER support"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_state_machine_t
block|{
name|SSL
modifier|*
name|ssl
decl_stmt|;
name|BIO
modifier|*
name|bio_intossl
decl_stmt|;
name|BIO
modifier|*
name|bio_fromssl
decl_stmt|;
name|buffer_t
name|clean_in
decl_stmt|,
name|clean_out
decl_stmt|;
name|buffer_t
name|dirty_in
decl_stmt|,
name|dirty_out
decl_stmt|;
block|}
name|state_machine_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|SM_CLEAN_IN
block|,
name|SM_CLEAN_OUT
block|,
name|SM_DIRTY_IN
block|,
name|SM_DIRTY_OUT
block|}
name|sm_buffer_t
typedef|;
end_typedef

begin_function_decl
name|void
name|state_machine_init
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|state_machine_close
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|buffer_t
modifier|*
name|state_machine_get_buffer
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|,
name|sm_buffer_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SSL
modifier|*
name|state_machine_get_SSL
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|state_machine_set_SSL
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|,
name|SSL
modifier|*
name|ssl
parameter_list|,
name|int
name|is_server
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Performs the data-IO loop and returns zero if the machine should close */
end_comment

begin_function_decl
name|int
name|state_machine_churn
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is used to handle closing conditions - namely when one side of the tunnel has  * closed but the other should finish flushing. */
end_comment

begin_function_decl
name|int
name|state_machine_close_clean
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|state_machine_close_dirty
parameter_list|(
name|state_machine_t
modifier|*
name|machine
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_TUNALA) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_IP
end_ifndef

begin_comment
comment|/* Initialise anything related to the networking. This includes blocking pesky  * SIGPIPE signals. */
end_comment

begin_function_decl
name|int
name|ip_initialise
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ip is the 4-byte ip address (eg. 127.0.0.1 is {0x7F,0x00,0x00,0x01}), port is  * the port to listen on (host byte order), and the return value is the  * file-descriptor or -1 on error. */
end_comment

begin_function_decl
name|int
name|ip_create_listener_split
parameter_list|(
specifier|const
name|char
modifier|*
name|ip
parameter_list|,
name|unsigned
name|short
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Same semantics as above. */
end_comment

begin_function_decl
name|int
name|ip_create_connection_split
parameter_list|(
specifier|const
name|char
modifier|*
name|ip
parameter_list|,
name|unsigned
name|short
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts a string into the ip/port before calling the above */
end_comment

begin_function_decl
name|int
name|ip_create_listener
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_create_connection
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Just does a string conversion on its own. NB: If accept_all_ip is non-zero,  * then the address string could be just a port. Ie. it's suitable for a  * listening address but not a connecting address. */
end_comment

begin_function_decl
name|int
name|ip_parse_address
parameter_list|(
specifier|const
name|char
modifier|*
name|address
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|parsed_ip
parameter_list|,
name|unsigned
name|short
modifier|*
name|port
parameter_list|,
name|int
name|accept_all_ip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Accepts an incoming connection through the listener. Assumes selects and  * what-not have deemed it an appropriate thing to do. */
end_comment

begin_function_decl
name|int
name|ip_accept_connection
parameter_list|(
name|int
name|listen_fd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NO_IP) */
end_comment

begin_comment
comment|/* These functions wrap up things that can be portability hassles. */
end_comment

begin_function_decl
name|int
name|int_strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|unsigned
name|long
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRSTR
end_ifdef

begin_define
define|#
directive|define
name|int_strstr
value|strstr
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|int_strstr
parameter_list|(
specifier|const
name|char
modifier|*
name|haystack
parameter_list|,
specifier|const
name|char
modifier|*
name|needle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_TUNALA_H) */
end_comment

end_unit

