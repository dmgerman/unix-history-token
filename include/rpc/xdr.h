begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)xdr.h 1.19 87/04/22 SMI  *	from: @(#)xdr.h	2.2 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * xdr.h, External Data Representation Serialization Routines.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_XDR_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_XDR_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * XDR provides a conventional way for converting between C data  * types and an external bit-string representation.  Library supplied  * routines provide for the conversion on built-in C data types.  These  * routines and utility routines defined here are used to help implement  * a type encode/decode routine for each user-defined type.  *  * Each data type provides a single procedure which takes two arguments:  *  *	bool_t  *	xdrproc(xdrs, argresp)  *		XDR *xdrs;  *<type> *argresp;  *  * xdrs is an instance of a XDR handle, to which or from which the data  * type is to be converted.  argresp is a pointer to the structure to be  * converted.  The XDR handle contains an operation field which indicates  * which of the operations (ENCODE, DECODE * or FREE) is to be performed.  *  * XDR_DECODE may allocate space if the pointer argresp is null.  This  * data can be freed with the XDR_FREE operation.  *  * We write only one procedure per data type to make it easy  * to keep the encode and decode procedures for a data type consistent.  * In many cases the same code performs all operations on a user defined type,  * because all the hard work is done in the component type routines.  * decode as a series of calls on the nested data types.  */
end_comment

begin_comment
comment|/*  * Xdr operations.  XDR_ENCODE causes the type to be encoded into the  * stream.  XDR_DECODE causes the type to be extracted from the stream.  * XDR_FREE can be used to release the space allocated by an XDR_DECODE  * request.  */
end_comment

begin_enum
enum|enum
name|xdr_op
block|{
name|XDR_ENCODE
init|=
literal|0
block|,
name|XDR_DECODE
init|=
literal|1
block|,
name|XDR_FREE
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/*  * This is the number of bytes per unit of external data.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_PER_XDR_UNIT
value|(4)
end_define

begin_define
define|#
directive|define
name|RNDUP
parameter_list|(
name|x
parameter_list|)
value|((((x) + BYTES_PER_XDR_UNIT - 1) / BYTES_PER_XDR_UNIT) \ 		    * BYTES_PER_XDR_UNIT)
end_define

begin_comment
comment|/*  * The XDR handle.  * Contains operation which is being applied to the stream,  * an operations vector for the particular implementation (e.g. see xdr_mem.c),  * and two private fields for the use of the particular implementation.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__rpc_xdr
block|{
name|enum
name|xdr_op
name|x_op
decl_stmt|;
comment|/* operation; fast additional param */
struct|struct
name|xdr_ops
block|{
comment|/* get a long from underlying stream */
name|bool_t
argument_list|(
argument|*x_getlong
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* put a long to underlying stream */
name|bool_t
argument_list|(
argument|*x_putlong
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* get some bytes from underlying stream */
name|bool_t
argument_list|(
argument|*x_getbytes
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|,
name|caddr_t
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
comment|/* put some bytes to underlying stream */
name|bool_t
argument_list|(
argument|*x_putbytes
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|,
name|caddr_t
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
comment|/* returns bytes off from beginning */
name|u_int
argument_list|(
argument|*x_getpostn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* lets you reposition the stream */
name|bool_t
argument_list|(
argument|*x_setpostn
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
comment|/* buf quick ptr to buffered data */
name|int32_t
operator|*
operator|(
operator|*
name|x_inline
operator|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
comment|/* free privates of this xdr_stream */
name|void
argument_list|(
argument|*x_destroy
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__rpc_xdr
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
modifier|*
name|x_ops
struct|;
name|caddr_t
name|x_public
decl_stmt|;
comment|/* users' data */
name|caddr_t
name|x_private
decl_stmt|;
comment|/* pointer to private data */
name|caddr_t
name|x_base
decl_stmt|;
comment|/* private used for position info */
name|int
name|x_handy
decl_stmt|;
comment|/* extra private word */
block|}
name|XDR
typedef|;
end_typedef

begin_comment
comment|/*  * A xdrproc_t exists for each data type which is to be encoded or decoded.  *  * The second argument to the xdrproc_t is a pointer to an opaque pointer.  * The opaque pointer generally points to a structure of the data type  * to be decoded.  If this pointer is 0, then the type routines should  * allocate dynamic storage of the appropriate size and return it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|bool_t
argument_list|(
argument|*xdrproc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|void
operator|*
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * XXX can't actually prototype it, because some take two args!!!  */
end_comment

begin_typedef
typedef|typedef
name|bool_t
argument_list|(
argument|*xdrproc_t
argument_list|)
name|__P
argument_list|(
operator|(
comment|/* XDR *, void *, u_int */
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Operations defined on a XDR handle  *  * XDR		*xdrs;  * long		*longp;  * caddr_t	 addr;  * u_int	 len;  * u_int	 pos;  */
end_comment

begin_define
define|#
directive|define
name|XDR_GETLONG
parameter_list|(
name|xdrs
parameter_list|,
name|longp
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_getlong)(xdrs, longp)
end_define

begin_define
define|#
directive|define
name|xdr_getlong
parameter_list|(
name|xdrs
parameter_list|,
name|longp
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_getlong)(xdrs, longp)
end_define

begin_define
define|#
directive|define
name|XDR_PUTLONG
parameter_list|(
name|xdrs
parameter_list|,
name|longp
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_putlong)(xdrs, longp)
end_define

begin_define
define|#
directive|define
name|xdr_putlong
parameter_list|(
name|xdrs
parameter_list|,
name|longp
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_putlong)(xdrs, longp)
end_define

begin_define
define|#
directive|define
name|XDR_GETBYTES
parameter_list|(
name|xdrs
parameter_list|,
name|addr
parameter_list|,
name|len
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_getbytes)(xdrs, addr, len)
end_define

begin_define
define|#
directive|define
name|xdr_getbytes
parameter_list|(
name|xdrs
parameter_list|,
name|addr
parameter_list|,
name|len
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_getbytes)(xdrs, addr, len)
end_define

begin_define
define|#
directive|define
name|XDR_PUTBYTES
parameter_list|(
name|xdrs
parameter_list|,
name|addr
parameter_list|,
name|len
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_putbytes)(xdrs, addr, len)
end_define

begin_define
define|#
directive|define
name|xdr_putbytes
parameter_list|(
name|xdrs
parameter_list|,
name|addr
parameter_list|,
name|len
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_putbytes)(xdrs, addr, len)
end_define

begin_define
define|#
directive|define
name|XDR_GETPOS
parameter_list|(
name|xdrs
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_getpostn)(xdrs)
end_define

begin_define
define|#
directive|define
name|xdr_getpos
parameter_list|(
name|xdrs
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_getpostn)(xdrs)
end_define

begin_define
define|#
directive|define
name|XDR_SETPOS
parameter_list|(
name|xdrs
parameter_list|,
name|pos
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_setpostn)(xdrs, pos)
end_define

begin_define
define|#
directive|define
name|xdr_setpos
parameter_list|(
name|xdrs
parameter_list|,
name|pos
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_setpostn)(xdrs, pos)
end_define

begin_define
define|#
directive|define
name|XDR_INLINE
parameter_list|(
name|xdrs
parameter_list|,
name|len
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_inline)(xdrs, len)
end_define

begin_define
define|#
directive|define
name|xdr_inline
parameter_list|(
name|xdrs
parameter_list|,
name|len
parameter_list|)
define|\
value|(*(xdrs)->x_ops->x_inline)(xdrs, len)
end_define

begin_define
define|#
directive|define
name|XDR_DESTROY
parameter_list|(
name|xdrs
parameter_list|)
define|\
value|if ((xdrs)->x_ops->x_destroy) 			\ 		(*(xdrs)->x_ops->x_destroy)(xdrs)
end_define

begin_define
define|#
directive|define
name|xdr_destroy
parameter_list|(
name|xdrs
parameter_list|)
define|\
value|if ((xdrs)->x_ops->x_destroy) 			\ 		(*(xdrs)->x_ops->x_destroy)(xdrs)
end_define

begin_comment
comment|/*  * Support struct for discriminated unions.  * You create an array of xdrdiscrim structures, terminated with  * a entry with a null procedure pointer.  The xdr_union routine gets  * the discriminant value and then searches the array of structures  * for a matching value.  If a match is found the associated xdr routine  * is called to handle that part of the union.  If there is  * no match, then a default routine may be called.  * If there is no match and no default routine it is an error.  */
end_comment

begin_define
define|#
directive|define
name|NULL_xdrproc_t
value|((xdrproc_t)0)
end_define

begin_struct
struct|struct
name|xdr_discrim
block|{
name|int
name|value
decl_stmt|;
name|xdrproc_t
name|proc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * In-line routines for fast encode/decode of primitive data types.  * Caveat emptor: these use single memory cycles to get the  * data from the underlying buffer, and will fail to operate  * properly if the data is not aligned.  The standard way to use these  * is to say:  *	if ((buf = XDR_INLINE(xdrs, count)) == NULL)  *		return (FALSE);  *<<< macro calls>>>  * where ``count'' is the number of bytes of data occupied  * by the primitive data types.  *  * N.B. and frozen for all time: each data type here uses 4 bytes  * of external representation.  */
end_comment

begin_define
define|#
directive|define
name|IXDR_GET_LONG
parameter_list|(
name|buf
parameter_list|)
value|((long)ntohl((u_long)*(buf)++))
end_define

begin_define
define|#
directive|define
name|IXDR_PUT_LONG
parameter_list|(
name|buf
parameter_list|,
name|v
parameter_list|)
value|(*(buf)++ = (long)htonl((u_long)v))
end_define

begin_define
define|#
directive|define
name|IXDR_GET_BOOL
parameter_list|(
name|buf
parameter_list|)
value|((bool_t)IXDR_GET_LONG(buf))
end_define

begin_define
define|#
directive|define
name|IXDR_GET_ENUM
parameter_list|(
name|buf
parameter_list|,
name|t
parameter_list|)
value|((t)IXDR_GET_LONG(buf))
end_define

begin_define
define|#
directive|define
name|IXDR_GET_U_LONG
parameter_list|(
name|buf
parameter_list|)
value|((u_long)IXDR_GET_LONG(buf))
end_define

begin_define
define|#
directive|define
name|IXDR_GET_SHORT
parameter_list|(
name|buf
parameter_list|)
value|((short)IXDR_GET_LONG(buf))
end_define

begin_define
define|#
directive|define
name|IXDR_GET_U_SHORT
parameter_list|(
name|buf
parameter_list|)
value|((u_short)IXDR_GET_LONG(buf))
end_define

begin_define
define|#
directive|define
name|IXDR_PUT_BOOL
parameter_list|(
name|buf
parameter_list|,
name|v
parameter_list|)
value|IXDR_PUT_LONG((buf), ((long)(v)))
end_define

begin_define
define|#
directive|define
name|IXDR_PUT_ENUM
parameter_list|(
name|buf
parameter_list|,
name|v
parameter_list|)
value|IXDR_PUT_LONG((buf), ((long)(v)))
end_define

begin_define
define|#
directive|define
name|IXDR_PUT_U_LONG
parameter_list|(
name|buf
parameter_list|,
name|v
parameter_list|)
value|IXDR_PUT_LONG((buf), ((long)(v)))
end_define

begin_define
define|#
directive|define
name|IXDR_PUT_SHORT
parameter_list|(
name|buf
parameter_list|,
name|v
parameter_list|)
value|IXDR_PUT_LONG((buf), ((long)(v)))
end_define

begin_define
define|#
directive|define
name|IXDR_PUT_U_SHORT
parameter_list|(
name|buf
parameter_list|,
name|v
parameter_list|)
value|IXDR_PUT_LONG((buf), ((long)(v)))
end_define

begin_comment
comment|/*  * These are the "generic" xdr routines.  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_void
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_int
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_u_int
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_long
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_u_long
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_short
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|short
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_u_short
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_short
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_int16_t
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|int16_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_u_int16_t
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_int16_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_int32_t
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_u_int32_t
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_int64_t
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|int64_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_u_int64_t
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_int64_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_bool
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|bool_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_enum
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|enum_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_array
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|u_int
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|xdrproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_bytes
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|u_int
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_opaque
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|caddr_t
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_string
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_union
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|enum_t
operator|*
operator|,
name|char
operator|*
operator|,
expr|struct
name|xdr_discrim
operator|*
operator|,
name|xdrproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|xdr_sizeof
name|__P
argument_list|(
operator|(
name|xdrproc_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_char
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_u_char
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_vector
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|xdrproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_float
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|float
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_double
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|double
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_reference
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|caddr_t
operator|*
operator|,
name|u_int
operator|,
name|xdrproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_pointer
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|caddr_t
operator|*
operator|,
name|u_int
operator|,
name|xdrproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_wrapstring
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xdr_free
name|__P
argument_list|(
operator|(
name|xdrproc_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * Common opaque bytes objects used by many rpc protocols;  * declared here due to commonality.  */
end_comment

begin_define
define|#
directive|define
name|MAX_NETOBJ_SZ
value|1024
end_define

begin_struct
struct|struct
name|netobj
block|{
name|u_int
name|n_len
decl_stmt|;
name|char
modifier|*
name|n_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|netobj
name|netobj
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bool_t
name|xdr_netobj
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
expr|struct
name|netobj
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These are the public routines for the various implementations of  * xdr streams.  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
comment|/* XDR using memory buffers */
specifier|extern
name|void
name|xdrmem_create
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|char
operator|*
operator|,
name|u_int
operator|,
expr|enum
name|xdr_op
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_STDIO_H_
end_ifdef

begin_comment
comment|/* XDR using stdio library */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|xdrstdio_create
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|FILE
operator|*
operator|,
expr|enum
name|xdr_op
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XDR pseudo records for tcp */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|xdrrec_create
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|,
name|char
operator|*
operator|,
name|int
argument_list|(
argument|*
argument_list|)
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
operator|,
name|int
argument_list|(
argument|*
argument_list|)
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* make end of xdr record */
end_comment

begin_decl_stmt
specifier|extern
name|bool_t
name|xdrrec_endofrecord
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* move to beginning of next record */
end_comment

begin_decl_stmt
specifier|extern
name|bool_t
name|xdrrec_skiprecord
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if no more input */
end_comment

begin_decl_stmt
specifier|extern
name|bool_t
name|xdrrec_eof
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_XDR_H */
end_comment

end_unit

