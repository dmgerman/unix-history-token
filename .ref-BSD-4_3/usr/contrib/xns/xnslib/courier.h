begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: courier.h,v 2.0 85/11/21 07:22:05 jqj Exp $ */
end_comment

begin_comment
comment|/*  $Log:	courier.h,v $  * Revision 2.0  85/11/21  07:22:05  jqj  * 4.3BSD standard release  *   * Revision 1.3  85/10/23  16:43:30  root  * Probably correct versions of basic conversion operators for the Gould.  *   * Revision 1.2  85/10/21  12:49:15  root  * Gould version:  definitions for MoveLong, etc. (the MoveLong routine is in misc.c)  *   * Revision 1.2  85/10/17  16:46:55  jqj  * first Gould version: definitions for MoveLong etc.  *   * Revision 1.5  85/05/23  06:18:06  jqj  * Public Beta-test version, released 24 May 1985  *   * Revision 1.3  85/03/11  16:36:54  jqj  * Public alpha-test version, released 11 March 1985  *   * Revision 1.2  85/01/27  07:37:18  jqj  * finished but undebugged version  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COURIERVERSION
end_ifndef

begin_comment
comment|/*  * the version of Courier we support  */
end_comment

begin_define
define|#
directive|define
name|COURIERVERSION
value|3
end_define

begin_comment
comment|/*  * Predefined Courier types.  */
end_comment

begin_typedef
typedef|typedef
name|char
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|Cardinal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|LongCardinal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|Integer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|LongInteger
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|String
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|Unspecified
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|LongUnspecified
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|NilRecord
typedef|;
end_typedef

begin_comment
comment|/*  * Low-level byte moving, with byte-swapping.  * Use these definitions for VAX and other low-enders.  */
end_comment

begin_if
if|#
directive|if
name|vax
end_if

begin_define
define|#
directive|define
name|externalize_Boolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|(*(short*)(buf) = *((char*)(p))<<8, 1)
end_define

begin_define
define|#
directive|define
name|internalize_Boolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|(*(char*)(p) = *((char*)(buf)+1), 1)
end_define

begin_define
define|#
directive|define
name|MoveShort
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(char*)(b) = *((char*)(a)+1),\ 			 *((char*)(b)+1) = *(char*)(a),1)
end_define

begin_define
define|#
directive|define
name|MoveLong
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(char*)(b) = *((char*)(a)+3),\ 			 *((char*)(b)+1) = *((char*)(a)+2),\ 			 *((char*)(b)+2) = *((char*)(a)+1),\ 			 *((char*)(b)+3) = *(char*)(a), 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Low-level byte moving, without byte-swapping.  * Use these definitions for SUN and other high-enders.  */
end_comment

begin_if
if|#
directive|if
name|sun
end_if

begin_define
define|#
directive|define
name|externalize_Boolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|(*(Unspecified*)(buf) = 1&*(char*)(p), 1)
end_define

begin_define
define|#
directive|define
name|internalize_Boolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|(*(char*)(p) = 1&*(Unspecified*)(buf), 1)
end_define

begin_define
define|#
directive|define
name|MoveShort
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(short *)(b) = *(short *)(a),1)
end_define

begin_define
define|#
directive|define
name|MoveLong
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(long *)(b) = *(long *)(a),2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Low-level byte moving, without byte-swapping.  * Use these definitions for sel and other high-enders that require  * longword alignment.  */
end_comment

begin_if
if|#
directive|if
name|sel
end_if

begin_define
define|#
directive|define
name|externalize_Boolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|(*(Unspecified*)(buf) = 1&*(char*)(p), 1)
end_define

begin_define
define|#
directive|define
name|internalize_Boolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|(*(p) = 1&*(Unspecified*)(buf), 1)
end_define

begin_define
define|#
directive|define
name|MoveShort
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(short *)(b) = *(short *)(a),1)
end_define

begin_function_decl
name|int
name|MoveLong
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * sizeof_Foo(p) is a function that returns the externalized size of  * the variable specified as argument (assumed to be of type Foo).  * clear_Foo(p) is a function that deallocates any components of Foo.  * externalize_Foo translates a variable from C form to external  * serialized form.  * internalize_Foo translates a variable from external serializedform   * to internal C form  */
end_comment

begin_define
define|#
directive|define
name|sizeof_NilRecord
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|clear_NilRecord
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|externalize_NilRecord
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|internalize_NilRecord
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|sizeof_Boolean
parameter_list|(
name|p
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|clear_Boolean
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|sizeof_Cardinal
parameter_list|(
name|p
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|clear_Cardinal
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|externalize_Cardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(p, buf)
end_define

begin_define
define|#
directive|define
name|internalize_Cardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(buf, p)
end_define

begin_define
define|#
directive|define
name|sizeof_LongCardinal
parameter_list|(
name|p
parameter_list|)
value|2
end_define

begin_define
define|#
directive|define
name|clear_LongCardinal
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|externalize_LongCardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(p, buf)
end_define

begin_define
define|#
directive|define
name|internalize_LongCardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(buf, p)
end_define

begin_define
define|#
directive|define
name|sizeof_Integer
parameter_list|(
name|p
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|clear_Integer
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|externalize_Integer
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(p, buf)
end_define

begin_define
define|#
directive|define
name|internalize_Integer
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(buf, p)
end_define

begin_define
define|#
directive|define
name|sizeof_LongInteger
parameter_list|(
name|p
parameter_list|)
value|2
end_define

begin_define
define|#
directive|define
name|clear_LongInteger
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|externalize_LongInteger
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(p, buf)
end_define

begin_define
define|#
directive|define
name|internalize_LongInteger
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(buf, p)
end_define

begin_define
define|#
directive|define
name|sizeof_Unspecified
parameter_list|(
name|p
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|clear_Unspecified
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|externalize_Unspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(p, buf)
end_define

begin_define
define|#
directive|define
name|internalize_Unspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(buf, p)
end_define

begin_define
define|#
directive|define
name|sizeof_LongUnspecified
parameter_list|(
name|p
parameter_list|)
value|2
end_define

begin_define
define|#
directive|define
name|clear_LongUnspecified
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|externalize_LongUnspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(p, buf)
end_define

begin_define
define|#
directive|define
name|internalize_LongUnspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(buf, p)
end_define

begin_comment
comment|/*   * SPP stream types used by Courier  */
end_comment

begin_define
define|#
directive|define
name|SPPSST_RPC
value|0
end_define

begin_define
define|#
directive|define
name|SPPSST_BDT
value|1
end_define

begin_define
define|#
directive|define
name|SPPSST_END
value|254
end_define

begin_define
define|#
directive|define
name|SPPSST_ENDREPLY
value|255
end_define

begin_comment
comment|/*  * the following should be in xn.h or spp.h  */
end_comment

begin_define
define|#
directive|define
name|IDPPORT_COURIER
value|5
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXWORDS
end_ifndef

begin_define
define|#
directive|define
name|MAXWORDS
value|267
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SPPMAXDATA
end_ifndef

begin_define
define|#
directive|define
name|SPPMAXDATA
value|(MAXWORDS*2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For streams  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|nextSegment
init|=
literal|0
block|,
name|lastSegment
init|=
literal|1
block|}
name|StreamEnumerator
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_StreamEnumerator
value|sizeof_enumeration
end_define

begin_define
define|#
directive|define
name|clear_StreamEnumerator
value|clear_enumeration
end_define

begin_define
define|#
directive|define
name|externalize_StreamEnumerator
value|externalize_enumeration
end_define

begin_define
define|#
directive|define
name|internalize_StreamEnumerator
value|internalize_enumeration
end_define

begin_comment
comment|/*  * miscellaneous structures and values used by Courier  * runtimes  */
end_comment

begin_comment
comment|/*   * message types for Courier messages (should be mixed case?)  * (should only be of interest to the runtimes)  */
end_comment

begin_define
define|#
directive|define
name|CALL
value|0
end_define

begin_define
define|#
directive|define
name|REJECT
value|1
end_define

begin_define
define|#
directive|define
name|RETURN
value|2
end_define

begin_define
define|#
directive|define
name|ABORT
value|3
end_define

begin_comment
comment|/*  * components of Courier error messages  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|lowest
decl_stmt|;
name|Cardinal
name|highest
decl_stmt|;
block|}
name|ImplementedVersionNumbers
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
enum|enum
block|{
name|unspecifiedError
init|=
literal|65535
block|,
name|invalidArgument
init|=
literal|3
block|,
name|noSuchProcedureValue
init|=
literal|2
block|,
name|noSuchVersionNumber
init|=
literal|1
block|,
name|noSuchProgramNumber
init|=
literal|0
block|}
name|designator
enum|;
union|union
block|{
name|NilRecord
name|u_noSuchProgramNumber
decl_stmt|;
define|#
directive|define
name|noSuchProgramNumber_case
value|u.u_noSuchProgramNumber
name|ImplementedVersionNumbers
name|u_noSuchVersionNumber
decl_stmt|;
define|#
directive|define
name|noSuchVersionNumber_case
value|u.u_noSuchVersionNumber
name|NilRecord
name|u_noSuchProcedureValue
decl_stmt|;
define|#
directive|define
name|noSuchProcedureValue_case
value|u.u_noSuchProcedureValue
name|NilRecord
name|u_invalidArgument
decl_stmt|;
define|#
directive|define
name|invalidArgument_case
value|u.u_invalidArgument
name|NilRecord
name|u_unspecifiedError
decl_stmt|;
define|#
directive|define
name|unspecifiedError_case
value|u.u_unspecifiedError
block|}
name|u
union|;
block|}
name|rejectionDetails
typedef|;
end_typedef

begin_comment
comment|/*  * Macro for unpacking error arguments given a typedef and a field name  */
end_comment

begin_define
define|#
directive|define
name|CourierErrArgs
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|(((type *)Exception.Message)->field)
end_define

begin_comment
comment|/*  * miscellaneous constants  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|((char*) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * exceptions defined in Courier  */
end_comment

begin_define
define|#
directive|define
name|REJECT_ERROR
value|65535
end_define

begin_define
define|#
directive|define
name|PROTOCOL_VIOLATION
value|65534
end_define

begin_comment
comment|/* plus all user-defined ERROR values, offset by ERROR_OFFSET */
end_comment

begin_define
define|#
directive|define
name|ERROR_OFFSET
value|65536
end_define

begin_comment
comment|/*  * External declarations.  */
end_comment

begin_function_decl
specifier|extern
name|Unspecified
modifier|*
name|Allocate
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Unspecified
modifier|*
name|ReceiveCallMessage
argument_list|()
decl_stmt|,
modifier|*
name|ReceiveReturnMessage
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Unspecified
modifier|*
name|ReadMessage
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|BDTwrite
argument_list|()
decl_stmt|,
name|BDTclosewrite
argument_list|()
decl_stmt|,
name|BDTread
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sppclose
argument_list|()
decl_stmt|,
name|sppclosereply
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|COURIERVERSION
end_endif

end_unit

