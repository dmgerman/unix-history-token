begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	courier.h	4.1	83/07/03	*/
end_comment

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

begin_define
define|#
directive|define
name|MoveByte
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|flag
parameter_list|)
value|(flag ? *(char *)(b) = *(char *)(a), 1 : 1)
end_define

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
name|MoveShort
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|flag
parameter_list|)
value|(flag ? *(char *)(b) = *((char *)(a)+1), *((char *)(b)+1) = *(char *)(a), 1 : 1)
end_define

begin_define
define|#
directive|define
name|MoveLong
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|flag
parameter_list|)
value|(flag ? *(char *)(b) = *((char *)(a)+3), *((char *)(b)+1) = *((char *)(a)+2), *((char *)(b)+2) = *((char *)(a)+1), *((char *)(b)+3) = *(char *)(a), 2 : 2)
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
name|MoveShort
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|flag
parameter_list|)
value|(flag ? *(short *)(b) = *(short *)(a), 1 : 1)
end_define

begin_define
define|#
directive|define
name|MoveLong
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|flag
parameter_list|)
value|(flag ? *(long *)(b) = *(long *)(a), 2 : 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PackBoolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|,
name|flag
parameter_list|)
value|MoveByte(p, buf, flag)
end_define

begin_define
define|#
directive|define
name|UnpackBoolean
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveByte(buf, p, 1)
end_define

begin_define
define|#
directive|define
name|PackCardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|,
name|flag
parameter_list|)
value|MoveShort(p, buf, flag)
end_define

begin_define
define|#
directive|define
name|UnpackCardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(buf, p, 1)
end_define

begin_define
define|#
directive|define
name|PackLongCardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|,
name|flag
parameter_list|)
value|MoveLong(p, buf, flag)
end_define

begin_define
define|#
directive|define
name|UnpackLongCardinal
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(buf, p, 1)
end_define

begin_define
define|#
directive|define
name|PackInteger
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|,
name|flag
parameter_list|)
value|MoveShort(p, buf, flag)
end_define

begin_define
define|#
directive|define
name|UnpackInteger
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(buf, p, 1)
end_define

begin_define
define|#
directive|define
name|PackLongInteger
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|,
name|flag
parameter_list|)
value|MoveLong(p, buf, flag)
end_define

begin_define
define|#
directive|define
name|UnpackLongInteger
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(buf, p, 1)
end_define

begin_define
define|#
directive|define
name|PackUnspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|,
name|flag
parameter_list|)
value|MoveShort(p, buf, flag)
end_define

begin_define
define|#
directive|define
name|UnpackUnspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveShort(buf, p, 1)
end_define

begin_define
define|#
directive|define
name|PackLongUnspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|,
name|flag
parameter_list|)
value|MoveLong(p, buf, flag)
end_define

begin_define
define|#
directive|define
name|UnpackLongUnspecified
parameter_list|(
name|p
parameter_list|,
name|buf
parameter_list|)
value|MoveLong(buf, p, 1)
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

end_unit

