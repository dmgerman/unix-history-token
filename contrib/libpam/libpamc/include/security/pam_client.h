begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: pam_client.h,v 1.4 2001/01/20 22:29:47 agmorgan Exp $  *  * Copyright (c) 1999 Andrew G. Morgan<morgan@linux.kernel.org>  *  * This header file provides the prototypes for the PAM client API  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_CLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|PAM_CLIENT_H
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* opaque agent handling structure */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pamc_handle_s
modifier|*
name|pamc_handle_t
typedef|;
end_typedef

begin_comment
comment|/* binary prompt structure pointer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__u32
end_ifndef

begin_define
define|#
directive|define
name|__u32
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__u8
end_ifndef

begin_define
define|#
directive|define
name|__u8
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u32
name|length
decl_stmt|;
name|__u8
name|control
decl_stmt|;
block|}
typedef|*
name|pamc_bp_t
typedef|;
end_typedef

begin_comment
comment|/*  * functions provided by libpamc  */
end_comment

begin_comment
comment|/*  * Initialize the agent abstraction library  */
end_comment

begin_function_decl
name|pamc_handle_t
name|pamc_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Terminate the authentication process  */
end_comment

begin_function_decl
name|int
name|pamc_end
parameter_list|(
name|pamc_handle_t
modifier|*
name|pch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * force the loading of a specified agent  */
end_comment

begin_function_decl
name|int
name|pamc_load
parameter_list|(
name|pamc_handle_t
name|pch
parameter_list|,
specifier|const
name|char
modifier|*
name|agent_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Single conversation interface for binary prompts  */
end_comment

begin_function_decl
name|int
name|pamc_converse
parameter_list|(
name|pamc_handle_t
name|pch
parameter_list|,
name|pamc_bp_t
modifier|*
name|prompt_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * disable an agent  */
end_comment

begin_function_decl
name|int
name|pamc_disable
parameter_list|(
name|pamc_handle_t
name|pch
parameter_list|,
specifier|const
name|char
modifier|*
name|agent_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * obtain a list of available agents  */
end_comment

begin_function_decl
name|char
modifier|*
modifier|*
name|pamc_list_agents
parameter_list|(
name|pamc_handle_t
name|pch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PAM_BP_ MACROS for creating, destroying and manipulating binary prompts  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_BP_ASSERT
end_ifndef

begin_define
define|#
directive|define
name|PAM_BP_ASSERT
parameter_list|(
name|x
parameter_list|)
value|do { printf(__FILE__ "(%d): %s\n", \ 					__LINE__, x) ; exit(1); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_BP_ASSERT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_BP_CALLOC
end_ifndef

begin_define
define|#
directive|define
name|PAM_BP_CALLOC
value|calloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_BP_CALLOC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_BP_FREE
end_ifndef

begin_define
define|#
directive|define
name|PAM_BP_FREE
value|free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_BP_FREE */
end_comment

begin_define
define|#
directive|define
name|__PAM_BP_WOCTET
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*((y) + (__u8 *)(x)))
end_define

begin_define
define|#
directive|define
name|__PAM_BP_ROCTET
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*((y) + (const __u8 *)(x)))
end_define

begin_define
define|#
directive|define
name|PAM_BP_MIN_SIZE
value|(sizeof(__u32) + sizeof(__u8))
end_define

begin_define
define|#
directive|define
name|PAM_BP_MAX_LENGTH
value|0x20000
end_define

begin_comment
comment|/* an advisory limit */
end_comment

begin_define
define|#
directive|define
name|PAM_BP_WCONTROL
parameter_list|(
name|x
parameter_list|)
value|(__PAM_BP_WOCTET(x,4))
end_define

begin_define
define|#
directive|define
name|PAM_BP_RCONTROL
parameter_list|(
name|x
parameter_list|)
value|(__PAM_BP_ROCTET(x,4))
end_define

begin_define
define|#
directive|define
name|PAM_BP_SIZE
parameter_list|(
name|x
parameter_list|)
value|((__PAM_BP_ROCTET(x,0)<<24)+      \ 			       (__PAM_BP_ROCTET(x,1)<<16)+      \ 			       (__PAM_BP_ROCTET(x,2)<< 8)+      \ 			       (__PAM_BP_ROCTET(x,3)    ))
end_define

begin_define
define|#
directive|define
name|PAM_BP_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(PAM_BP_SIZE(x) - PAM_BP_MIN_SIZE)
end_define

begin_define
define|#
directive|define
name|PAM_BP_WDATA
parameter_list|(
name|x
parameter_list|)
value|(PAM_BP_MIN_SIZE + (__u8 *) (x))
end_define

begin_define
define|#
directive|define
name|PAM_BP_RDATA
parameter_list|(
name|x
parameter_list|)
value|(PAM_BP_MIN_SIZE + (const __u8 *) (x))
end_define

begin_comment
comment|/* Note, this macro always '\0' terminates renewed packets */
end_comment

begin_define
define|#
directive|define
name|PAM_BP_RENEW
parameter_list|(
name|old_p
parameter_list|,
name|cntrl
parameter_list|,
name|data_length
parameter_list|)
define|\
value|do {                                                                       \     if (old_p) {                                                           \ 	if (*(old_p)) {                                                    \ 	    __u32 __size;                                                  \             __size = PAM_BP_SIZE(*(old_p));                                \ 	    memset(*(old_p), 0, __size);                                   \ 	    PAM_BP_FREE(*(old_p));                                         \ 	}                                                                  \ 	if (cntrl) {                                                       \ 	    __u32 __size;                                                  \                                                                            \ 	    __size = PAM_BP_MIN_SIZE + data_length;                        \ 	    if ((*(old_p) = PAM_BP_CALLOC(1, 1+__size))) {                 \  		__PAM_BP_WOCTET(*(old_p), 3) =  __size& 0xFF;        \ 		__PAM_BP_WOCTET(*(old_p), 2) = (__size>>=8)& 0xFF;        \ 		__PAM_BP_WOCTET(*(old_p), 1) = (__size>>=8)& 0xFF;        \ 		__PAM_BP_WOCTET(*(old_p), 0) = (__size>>=8)& 0xFF;        \ 		(*(old_p))->control = cntrl;                               \ 	    } else {                                                       \ 		PAM_BP_ASSERT("out of memory for binary prompt");          \ 	    }                                                              \ 	} else {                                                           \ 	    *old_p = NULL;                                                 \ 	}                                                                  \     } else {                                                               \ 	PAM_BP_ASSERT("programming error, invalid binary prompt pointer"); \     }                                                                      \ } while (0)
end_define

begin_define
define|#
directive|define
name|PAM_BP_FILL
parameter_list|(
name|prmpt
parameter_list|,
name|offset
parameter_list|,
name|length
parameter_list|,
name|data
parameter_list|)
define|\
value|do {                                                                       \     int bp_length;                                                         \     __u8 *prompt = (__u8 *) (prmpt);                                       \     bp_length = PAM_BP_LENGTH(prompt);                                     \     if (bp_length< ((length)+(offset))) {                                 \ 	PAM_BP_ASSERT("attempt to write over end of prompt");              \     }                                                                      \     memcpy((offset) + PAM_BP_WDATA(prompt), (data), (length));             \ } while (0)
end_define

begin_define
define|#
directive|define
name|PAM_BP_EXTRACT
parameter_list|(
name|prmpt
parameter_list|,
name|offset
parameter_list|,
name|length
parameter_list|,
name|data
parameter_list|)
define|\
value|do {                                                                       \     int __bp_length;                                                       \     const __u8 *__prompt = (const __u8 *) (prmpt);                         \     __bp_length = PAM_BP_LENGTH(__prompt);                                 \     if (((offset)< 0) || (__bp_length< ((length)+(offset)))              \ 	|| ((length)< 0)) {                                               \ 	PAM_BP_ASSERT("invalid extraction from prompt");                   \     }                                                                      \     memcpy((data), (offset) + PAM_BP_RDATA(__prompt), (length));           \ } while (0)
end_define

begin_comment
comment|/* Control types */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|PAM_BPC_TRUE
value|1
end_define

begin_define
define|#
directive|define
name|PAM_BPC_OK
value|0x01
end_define

begin_comment
comment|/* continuation packet   */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_SELECT
value|0x02
end_define

begin_comment
comment|/* initialization packet */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_DONE
value|0x03
end_define

begin_comment
comment|/* termination packet    */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_FAIL
value|0x04
end_define

begin_comment
comment|/* unable to execute     */
end_comment

begin_comment
comment|/* The following control characters are only legal for echanges    between an agent and a client (it is the responsibility of the    client to enforce this rule in the face of a rogue server): */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_GETENV
value|0x41
end_define

begin_comment
comment|/* obtain client env.var */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_PUTENV
value|0x42
end_define

begin_comment
comment|/* set client env.var    */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_TEXT
value|0x43
end_define

begin_comment
comment|/* display message       */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_ERROR
value|0x44
end_define

begin_comment
comment|/* display error message */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_PROMPT
value|0x45
end_define

begin_comment
comment|/* echo'd text prompt    */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_PASS
value|0x46
end_define

begin_comment
comment|/* non-echo'd text prompt*/
end_comment

begin_comment
comment|/* quick check for prompts that are legal for the client (by    implication the server too) to send to libpamc */
end_comment

begin_define
define|#
directive|define
name|PAM_BPC_FOR_CLIENT
parameter_list|(
comment|/* pamc_bp_t */
name|prompt
parameter_list|)
define|\
value|(((prompt)->control<= PAM_BPC_FAIL&& (prompt)->control>= PAM_BPC_OK)   \      ? PAM_BPC_TRUE:PAM_BPC_FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_CLIENT_H */
end_comment

end_unit

