begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Attribution notice: Rainbow have generously allowed me to reproduce  * the necessary definitions here from their API. This means the support  * can build independently of whether application builders have the  * API or hardware. This will allow developers to easily produce software  * that has latent hardware support for any users that have accelertors  * installed, without the developers themselves needing anything extra.  *  * I have only clipped the parts from the CryptoSwift header files that  * are (or seem) relevant to the CryptoSwift support code. This is  * simply to keep the file sizes reasonable.  * [Geoff]  */
end_comment

begin_comment
comment|/* NB: These type widths do *not* seem right in general, in particular  * they're not terribly friendly to 64-bit architectures (unsigned long)  * will be 64-bit on IA-64 for a start. I'm leaving these alone as they  * agree with Rainbow's API and this will only be called into question  * on platforms with Rainbow support anyway! ;-) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
typedef|typedef
name|long
name|SW_STATUS
typedef|;
comment|/* status           */
typedef|typedef
name|unsigned
name|char
name|SW_BYTE
typedef|;
comment|/* 8 bit byte       */
typedef|typedef
name|unsigned
name|short
name|SW_U16
typedef|;
comment|/* 16 bit number    */
if|#
directive|if
name|defined
argument_list|(
name|_IRIX
argument_list|)
include|#
directive|include
file|<sgidefs.h>
typedef|typedef
name|__uint32_t
name|SW_U32
typedef|;
else|#
directive|else
typedef|typedef
name|unsigned
name|long
name|SW_U32
typedef|;
comment|/* 32 bit integer   */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_SYS_WIN32
argument_list|)
typedef|typedef
struct|struct
name|_SW_U64
block|{
name|SW_U32
name|low32
decl_stmt|;
name|SW_U32
name|high32
decl_stmt|;
block|}
name|SW_U64
typedef|;
comment|/* 64 bit integer   */
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSSL_SYS_MACINTOSH_CLASSIC
argument_list|)
typedef|typedef
name|longlong
name|SW_U64
else|#
directive|else
comment|/* Unix variants */
typedef|typedef
struct|struct
name|_SW_U64
block|{
name|SW_U32
name|low32
decl_stmt|;
name|SW_U32
name|high32
decl_stmt|;
block|}
name|SW_U64
typedef|;
comment|/* 64 bit integer   */
endif|#
directive|endif
comment|/* status codes */
define|#
directive|define
name|SW_OK
value|(0L)
define|#
directive|define
name|SW_ERR_BASE
value|(-10000L)
define|#
directive|define
name|SW_ERR_NO_CARD
value|(SW_ERR_BASE-1)
comment|/* The Card is not present   */
define|#
directive|define
name|SW_ERR_CARD_NOT_READY
value|(SW_ERR_BASE-2)
comment|/* The card has not powered  */
comment|/*    up yet                 */
define|#
directive|define
name|SW_ERR_TIME_OUT
value|(SW_ERR_BASE-3)
comment|/* Execution of a command    */
comment|/*    time out               */
define|#
directive|define
name|SW_ERR_NO_EXECUTE
value|(SW_ERR_BASE-4)
comment|/* The Card failed to        */
comment|/*    execute the command    */
define|#
directive|define
name|SW_ERR_INPUT_NULL_PTR
value|(SW_ERR_BASE-5)
comment|/* a required pointer is     */
comment|/*    NULL                   */
define|#
directive|define
name|SW_ERR_INPUT_SIZE
value|(SW_ERR_BASE-6)
comment|/* size is invalid, too      */
comment|/*    small, too large.      */
define|#
directive|define
name|SW_ERR_INVALID_HANDLE
value|(SW_ERR_BASE-7)
comment|/* Invalid SW_ACC_CONTEXT    */
comment|/*    handle                 */
define|#
directive|define
name|SW_ERR_PENDING
value|(SW_ERR_BASE-8)
comment|/* A request is already out- */
comment|/*    standing at this       */
comment|/*    context handle         */
define|#
directive|define
name|SW_ERR_AVAILABLE
value|(SW_ERR_BASE-9)
comment|/* A result is available.    */
define|#
directive|define
name|SW_ERR_NO_PENDING
value|(SW_ERR_BASE-10)
comment|/* No request is pending.    */
define|#
directive|define
name|SW_ERR_NO_MEMORY
value|(SW_ERR_BASE-11)
comment|/* Not enough memory         */
define|#
directive|define
name|SW_ERR_BAD_ALGORITHM
value|(SW_ERR_BASE-12)
comment|/* Invalid algorithm type    */
comment|/*    in SW_PARAM structure  */
define|#
directive|define
name|SW_ERR_MISSING_KEY
value|(SW_ERR_BASE-13)
comment|/* No key is associated with */
comment|/*    context.               */
comment|/*    swAttachKeyParam() is  */
comment|/*    not called.            */
define|#
directive|define
name|SW_ERR_KEY_CMD_MISMATCH
define|\
value|(SW_ERR_BASE-14)
comment|/* Cannot perform requested  */
comment|/*    SW_COMMAND_CODE since  */
comment|/*    key attached via       */
comment|/*    swAttachKeyParam()     */
comment|/*    cannot be used for this*/
comment|/*    SW_COMMAND_CODE.       */
define|#
directive|define
name|SW_ERR_NOT_IMPLEMENTED
define|\
value|(SW_ERR_BASE-15)
comment|/* Not implemented           */
define|#
directive|define
name|SW_ERR_BAD_COMMAND
value|(SW_ERR_BASE-16)
comment|/* Bad command code          */
define|#
directive|define
name|SW_ERR_BAD_ITEM_SIZE
value|(SW_ERR_BASE-17)
comment|/* too small or too large in */
comment|/*    the "initems" or       */
comment|/*    "outitems".            */
define|#
directive|define
name|SW_ERR_BAD_ACCNUM
value|(SW_ERR_BASE-18)
comment|/* Bad accelerator number    */
define|#
directive|define
name|SW_ERR_SELFTEST_FAIL
value|(SW_ERR_BASE-19)
comment|/* At least one of the self  */
comment|/*    test fail, look at the */
comment|/*    selfTestBitmap in      */
comment|/*    SW_ACCELERATOR_INFO for*/
comment|/*    details.               */
define|#
directive|define
name|SW_ERR_MISALIGN
value|(SW_ERR_BASE-20)
comment|/* Certain alogrithms require*/
comment|/*    key materials aligned  */
comment|/*    in certain order, e.g. */
comment|/*    128 bit for CRT        */
define|#
directive|define
name|SW_ERR_OUTPUT_NULL_PTR
define|\
value|(SW_ERR_BASE-21)
comment|/* a required pointer is     */
comment|/*    NULL                   */
define|#
directive|define
name|SW_ERR_OUTPUT_SIZE
define|\
value|(SW_ERR_BASE-22)
comment|/* size is invalid, too      */
comment|/*    small, too large.      */
define|#
directive|define
name|SW_ERR_FIRMWARE_CHECKSUM
define|\
value|(SW_ERR_BASE-23)
comment|/* firmware checksum mismatch*/
comment|/*    download failed.       */
define|#
directive|define
name|SW_ERR_UNKNOWN_FIRMWARE
define|\
value|(SW_ERR_BASE-24)
comment|/* unknown firmware error    */
define|#
directive|define
name|SW_ERR_INTERRUPT
value|(SW_ERR_BASE-25)
comment|/* request is abort when     */
comment|/*    it's waiting to be     */
comment|/*    completed.             */
define|#
directive|define
name|SW_ERR_NVWRITE_FAIL
value|(SW_ERR_BASE-26)
comment|/* error in writing to Non-  */
comment|/*    volatile memory        */
define|#
directive|define
name|SW_ERR_NVWRITE_RANGE
value|(SW_ERR_BASE-27)
comment|/* out of range error in     */
comment|/*    writing to NV memory   */
define|#
directive|define
name|SW_ERR_RNG_ERROR
value|(SW_ERR_BASE-28)
comment|/* Random Number Generation  */
comment|/*    failure                */
define|#
directive|define
name|SW_ERR_DSS_FAILURE
value|(SW_ERR_BASE-29)
comment|/* DSS Sign or Verify failure*/
define|#
directive|define
name|SW_ERR_MODEXP_FAILURE
value|(SW_ERR_BASE-30)
comment|/* Failure in various math   */
comment|/*    calculations           */
define|#
directive|define
name|SW_ERR_ONBOARD_MEMORY
value|(SW_ERR_BASE-31)
comment|/* Error in accessing on -   */
comment|/*    board memory           */
define|#
directive|define
name|SW_ERR_FIRMWARE_VERSION
define|\
value|(SW_ERR_BASE-32)
comment|/* Wrong version in firmware */
comment|/*    update                 */
define|#
directive|define
name|SW_ERR_ZERO_WORKING_ACCELERATOR
define|\
value|(SW_ERR_BASE-44)
comment|/* All accelerators are bad  */
comment|/* algorithm type */
define|#
directive|define
name|SW_ALG_CRT
value|1
define|#
directive|define
name|SW_ALG_EXP
value|2
define|#
directive|define
name|SW_ALG_DSA
value|3
define|#
directive|define
name|SW_ALG_NVDATA
value|4
comment|/* command code */
define|#
directive|define
name|SW_CMD_MODEXP_CRT
value|1
comment|/* perform Modular Exponentiation using  */
comment|/*  Chinese Remainder Theorem (CRT)      */
define|#
directive|define
name|SW_CMD_MODEXP
value|2
comment|/* perform Modular Exponentiation        */
define|#
directive|define
name|SW_CMD_DSS_SIGN
value|3
comment|/* perform DSS sign                      */
define|#
directive|define
name|SW_CMD_DSS_VERIFY
value|4
comment|/* perform DSS verify                    */
define|#
directive|define
name|SW_CMD_RAND
value|5
comment|/* perform random number generation      */
define|#
directive|define
name|SW_CMD_NVREAD
value|6
comment|/* perform read to nonvolatile RAM       */
define|#
directive|define
name|SW_CMD_NVWRITE
value|7
comment|/* perform write to nonvolatile RAM      */
typedef|typedef
name|SW_U32
name|SW_ALGTYPE
typedef|;
comment|/* alogrithm type   */
typedef|typedef
name|SW_U32
name|SW_STATE
typedef|;
comment|/* state            */
typedef|typedef
name|SW_U32
name|SW_COMMAND_CODE
typedef|;
comment|/* command code     */
typedef|typedef
name|SW_U32
name|SW_COMMAND_BITMAP
index|[
literal|4
index|]
typedef|;
comment|/* bitmap           */
typedef|typedef
struct|struct
name|_SW_LARGENUMBER
block|{
name|SW_U32
name|nbytes
decl_stmt|;
comment|/* number of bytes in the buffer "value"  */
name|SW_BYTE
modifier|*
name|value
decl_stmt|;
comment|/* the large integer as a string of       */
comment|/*   bytes in network (big endian) order  */
block|}
name|SW_LARGENUMBER
typedef|;
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_SYS_WIN32
argument_list|)
include|#
directive|include
file|<windows.h>
typedef|typedef
name|HANDLE
name|SW_OSHANDLE
typedef|;
comment|/* handle to kernel object */
define|#
directive|define
name|SW_OS_INVALID_HANDLE
value|INVALID_HANDLE_VALUE
define|#
directive|define
name|SW_CALLCONV
value|_stdcall
elif|#
directive|elif
name|defined
argument_list|(
name|OPENSSL_SYS_MACINTOSH_CLASSIC
argument_list|)
comment|/* async callback mechanisms */
comment|/* swiftCallbackLevel */
define|#
directive|define
name|SW_MAC_CALLBACK_LEVEL_NO
value|0
define|#
directive|define
name|SW_MAC_CALLBACK_LEVEL_HARDWARE
value|1
comment|/* from the hardware ISR */
define|#
directive|define
name|SW_MAC_CALLBACK_LEVEL_SECONDARY
value|2
comment|/* as secondary ISR */
typedef|typedef
name|int
name|SW_MAC_CALLBACK_LEVEL
typedef|;
typedef|typedef
name|int
name|SW_OSHANDLE
typedef|;
define|#
directive|define
name|SW_OS_INVALID_HANDLE
value|(-1)
define|#
directive|define
name|SW_CALLCONV
else|#
directive|else
comment|/* Unix variants */
typedef|typedef
name|int
name|SW_OSHANDLE
typedef|;
comment|/* handle to driver */
define|#
directive|define
name|SW_OS_INVALID_HANDLE
value|(-1)
define|#
directive|define
name|SW_CALLCONV
endif|#
directive|endif
typedef|typedef
struct|struct
name|_SW_CRT
block|{
name|SW_LARGENUMBER
name|p
decl_stmt|;
comment|/* prime number p                         */
name|SW_LARGENUMBER
name|q
decl_stmt|;
comment|/* prime number q                         */
name|SW_LARGENUMBER
name|dmp1
decl_stmt|;
comment|/* exponent1                              */
name|SW_LARGENUMBER
name|dmq1
decl_stmt|;
comment|/* exponent2                              */
name|SW_LARGENUMBER
name|iqmp
decl_stmt|;
comment|/* CRT coefficient                        */
block|}
name|SW_CRT
typedef|;
typedef|typedef
struct|struct
name|_SW_EXP
block|{
name|SW_LARGENUMBER
name|modulus
decl_stmt|;
comment|/* modulus                                */
name|SW_LARGENUMBER
name|exponent
decl_stmt|;
comment|/* exponent                               */
block|}
name|SW_EXP
typedef|;
typedef|typedef
struct|struct
name|_SW_DSA
block|{
name|SW_LARGENUMBER
name|p
decl_stmt|;
comment|/*                                        */
name|SW_LARGENUMBER
name|q
decl_stmt|;
comment|/*                                        */
name|SW_LARGENUMBER
name|g
decl_stmt|;
comment|/*                                        */
name|SW_LARGENUMBER
name|key
decl_stmt|;
comment|/* private/public key                     */
block|}
name|SW_DSA
typedef|;
typedef|typedef
struct|struct
name|_SW_NVDATA
block|{
name|SW_U32
name|accnum
decl_stmt|;
comment|/* accelerator board number               */
name|SW_U32
name|offset
decl_stmt|;
comment|/* offset in byte                         */
block|}
name|SW_NVDATA
typedef|;
typedef|typedef
struct|struct
name|_SW_PARAM
block|{
name|SW_ALGTYPE
name|type
decl_stmt|;
comment|/* type of the alogrithm                  */
union|union
block|{
name|SW_CRT
name|crt
decl_stmt|;
name|SW_EXP
name|exp
decl_stmt|;
name|SW_DSA
name|dsa
decl_stmt|;
name|SW_NVDATA
name|nvdata
decl_stmt|;
block|}
name|up
union|;
block|}
name|SW_PARAM
typedef|;
typedef|typedef
name|SW_U32
name|SW_CONTEXT_HANDLE
typedef|;
comment|/* opaque context handle */
comment|/* Now the OpenSSL bits, these function types are the for the function  * pointers that will bound into the Rainbow shared libraries. */
typedef|typedef
name|SW_STATUS
name|SW_CALLCONV
name|t_swAcquireAccContext
parameter_list|(
name|SW_CONTEXT_HANDLE
modifier|*
name|hac
parameter_list|)
function_decl|;
typedef|typedef
name|SW_STATUS
name|SW_CALLCONV
name|t_swAttachKeyParam
parameter_list|(
name|SW_CONTEXT_HANDLE
name|hac
parameter_list|,
name|SW_PARAM
modifier|*
name|key_params
parameter_list|)
function_decl|;
typedef|typedef
name|SW_STATUS
name|SW_CALLCONV
name|t_swSimpleRequest
parameter_list|(
name|SW_CONTEXT_HANDLE
name|hac
parameter_list|,
name|SW_COMMAND_CODE
name|cmd
parameter_list|,
name|SW_LARGENUMBER
name|pin
index|[]
parameter_list|,
name|SW_U32
name|pin_count
parameter_list|,
name|SW_LARGENUMBER
name|pout
index|[]
parameter_list|,
name|SW_U32
name|pout_count
parameter_list|)
function_decl|;
typedef|typedef
name|SW_STATUS
name|SW_CALLCONV
name|t_swReleaseAccContext
parameter_list|(
name|SW_CONTEXT_HANDLE
name|hac
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

end_unit

