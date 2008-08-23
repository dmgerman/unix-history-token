begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This header declares the necessary definitions for using the exponentiation  * acceleration capabilities, and rnd number generation of the AEP card.   *  */
end_comment

begin_comment
comment|/*  *  * Some AEP defines  *  */
end_comment

begin_comment
comment|/*Successful return value*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_OK
value|0x00000000
end_define

begin_comment
comment|/*Miscelleanous unsuccessful return value*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_GENERAL_ERROR
value|0x10000001
end_define

begin_comment
comment|/*Insufficient host memory*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_HOST_MEMORY
value|0x10000002
end_define

begin_define
define|#
directive|define
name|AEP_R_FUNCTION_FAILED
value|0x10000006
end_define

begin_comment
comment|/*Invalid arguments in function call*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_ARGUMENTS_BAD
value|0x10020000
end_define

begin_define
define|#
directive|define
name|AEP_R_NO_TARGET_RESOURCES
value|0x10030000
end_define

begin_comment
comment|/*Error occuring on socket operation*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_SOCKERROR
value|0x10000010
end_define

begin_comment
comment|/*Socket has been closed from the other end*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_SOCKEOF
value|0x10000011
end_define

begin_comment
comment|/*Invalid handles*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_CONNECTION_HANDLE_INVALID
value|0x100000B3
end_define

begin_define
define|#
directive|define
name|AEP_R_TRANSACTION_HANDLE_INVALID
value|0x10040000
end_define

begin_comment
comment|/*Transaction has not yet returned from accelerator*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_TRANSACTION_NOT_READY
value|0x00010000
end_define

begin_comment
comment|/*There is already a thread waiting on this transaction*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_TRANSACTION_CLAIMED
value|0x10050000
end_define

begin_comment
comment|/*The transaction timed out*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_TIMED_OUT
value|0x10060000
end_define

begin_define
define|#
directive|define
name|AEP_R_FXN_NOT_IMPLEMENTED
value|0x10070000
end_define

begin_define
define|#
directive|define
name|AEP_R_TARGET_ERROR
value|0x10080000
end_define

begin_comment
comment|/*Error in the AEP daemon process*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_DAEMON_ERROR
value|0x10090000
end_define

begin_comment
comment|/*Invalid ctx id*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_INVALID_CTX_ID
value|0x10009000
end_define

begin_define
define|#
directive|define
name|AEP_R_NO_KEY_MANAGER
value|0x1000a000
end_define

begin_comment
comment|/*Error obtaining a mutex*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_MUTEX_BAD
value|0x000001A0
end_define

begin_comment
comment|/*Fxn call before AEP_Initialise ot after AEP_Finialise*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_AEPAPI_NOT_INITIALIZED
value|0x10000190
end_define

begin_comment
comment|/*AEP_Initialise has already been called*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_AEPAPI_ALREADY_INITIALIZED
value|0x10000191
end_define

begin_comment
comment|/*Maximum number of connections to daemon reached*/
end_comment

begin_define
define|#
directive|define
name|AEP_R_NO_MORE_CONNECTION_HNDLS
value|0x10000200
end_define

begin_comment
comment|/*  *  * Some AEP Type definitions  *  */
end_comment

begin_comment
comment|/* an unsigned 8-bit value */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|AEP_U8
typedef|;
end_typedef

begin_comment
comment|/* an unsigned 8-bit character */
end_comment

begin_typedef
typedef|typedef
name|char
name|AEP_CHAR
typedef|;
end_typedef

begin_comment
comment|/* a BYTE-sized Boolean flag */
end_comment

begin_typedef
typedef|typedef
name|AEP_U8
name|AEP_BBOOL
typedef|;
end_typedef

begin_comment
comment|/*Unsigned value, at least 16 bits long*/
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|AEP_U16
typedef|;
end_typedef

begin_comment
comment|/* an unsigned value, at least 32 bits long */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIXTY_FOUR_BIT_LONG
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|AEP_U32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|AEP_U32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIXTY_FOUR_BIT_LONG
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|AEP_U64
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|l1
decl_stmt|,
name|l2
decl_stmt|;
block|}
name|AEP_U64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* at least 32 bits; each bit is a Boolean flag */
end_comment

begin_typedef
typedef|typedef
name|AEP_U32
name|AEP_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_U8
modifier|*
name|AEP_U8_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_CHAR
modifier|*
name|AEP_CHAR_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_U32
modifier|*
name|AEP_U32_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_U64
modifier|*
name|AEP_U64_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|AEP_VOID_PTR
typedef|;
end_typedef

begin_comment
comment|/* Pointer to a AEP_VOID_PTR-- i.e., pointer to pointer to void */
end_comment

begin_typedef
typedef|typedef
name|AEP_VOID_PTR
modifier|*
name|AEP_VOID_PTR_PTR
typedef|;
end_typedef

begin_comment
comment|/*Used to identify an AEP connection handle*/
end_comment

begin_typedef
typedef|typedef
name|AEP_U32
name|AEP_CONNECTION_HNDL
typedef|;
end_typedef

begin_comment
comment|/*Pointer to an AEP connection handle*/
end_comment

begin_typedef
typedef|typedef
name|AEP_CONNECTION_HNDL
modifier|*
name|AEP_CONNECTION_HNDL_PTR
typedef|;
end_typedef

begin_comment
comment|/*Used by an application (in conjunction with the apps process id) to  identify an individual transaction*/
end_comment

begin_typedef
typedef|typedef
name|AEP_U32
name|AEP_TRANSACTION_ID
typedef|;
end_typedef

begin_comment
comment|/*Pointer to an applications transaction identifier*/
end_comment

begin_typedef
typedef|typedef
name|AEP_TRANSACTION_ID
modifier|*
name|AEP_TRANSACTION_ID_PTR
typedef|;
end_typedef

begin_comment
comment|/*Return value type*/
end_comment

begin_typedef
typedef|typedef
name|AEP_U32
name|AEP_RV
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_PROCESS_CONNECTIONS
value|256
end_define

begin_define
define|#
directive|define
name|RAND_BLK_SIZE
value|1024
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|NotConnected
init|=
literal|0
block|,
name|Connected
init|=
literal|1
block|,
name|InUse
init|=
literal|2
block|}
name|AEP_CONNECTION_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|AEP_CONNECTION_ENTRY
block|{
name|AEP_CONNECTION_STATE
name|conn_state
decl_stmt|;
name|AEP_CONNECTION_HNDL
name|conn_hndl
decl_stmt|;
block|}
name|AEP_CONNECTION_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_OpenConnection
parameter_list|(
name|AEP_CONNECTION_HNDL_PTR
name|phConnection
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_CloseConnection
parameter_list|(
name|AEP_CONNECTION_HNDL
name|hConnection
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_ModExp
parameter_list|(
name|AEP_CONNECTION_HNDL
name|hConnection
parameter_list|,
name|AEP_VOID_PTR
name|pA
parameter_list|,
name|AEP_VOID_PTR
name|pP
parameter_list|,
name|AEP_VOID_PTR
name|pN
parameter_list|,
name|AEP_VOID_PTR
name|pResult
parameter_list|,
name|AEP_TRANSACTION_ID
modifier|*
name|pidTransID
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_ModExpCrt
parameter_list|(
name|AEP_CONNECTION_HNDL
name|hConnection
parameter_list|,
name|AEP_VOID_PTR
name|pA
parameter_list|,
name|AEP_VOID_PTR
name|pP
parameter_list|,
name|AEP_VOID_PTR
name|pQ
parameter_list|,
name|AEP_VOID_PTR
name|pDmp1
parameter_list|,
name|AEP_VOID_PTR
name|pDmq1
parameter_list|,
name|AEP_VOID_PTR
name|pIqmp
parameter_list|,
name|AEP_VOID_PTR
name|pResult
parameter_list|,
name|AEP_TRANSACTION_ID
modifier|*
name|pidTransID
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|AEPRAND
end_ifdef

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_GenRandom
parameter_list|(
name|AEP_CONNECTION_HNDL
name|hConnection
parameter_list|,
name|AEP_U32
name|Len
parameter_list|,
name|AEP_U32
name|Type
parameter_list|,
name|AEP_VOID_PTR
name|pResult
parameter_list|,
name|AEP_TRANSACTION_ID
modifier|*
name|pidTransID
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_Initialize
parameter_list|(
name|AEP_VOID_PTR
name|pInitArgs
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_Finalize
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|AEP_RV
name|t_AEP_SetBNCallBacks
parameter_list|(
name|AEP_RV
function_decl|(
modifier|*
name|GetBigNumSizeFunc
function_decl|)
parameter_list|()
parameter_list|,
name|AEP_RV
function_decl|(
modifier|*
name|MakeAEPBigNumFunc
function_decl|)
parameter_list|()
parameter_list|,
name|AEP_RV
function_decl|(
modifier|*
name|ConverAEPBigNumFunc
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_typedef

end_unit

