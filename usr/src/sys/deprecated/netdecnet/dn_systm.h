begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dn_systm.h	1.3	82/10/09	*/
end_comment

begin_comment
comment|/*  * Miscellaneous DECnet definitions for kernel  */
end_comment

begin_comment
comment|/*  * Network types.  *  * The DECnet protocols often use unaligned 16 bit fields  * as integers.  The d_short type represents such a field  * in a protocol structure definition and the D_SHORT macro  * extracts such a field given a pointer to the first byte.  * The AD_SHORT macro assigns to such a field.  * On the VAX it's easy since unaligned references are  * allowed, on the 11 it would be a bit harder.  */
end_comment

begin_typedef
typedef|typedef
name|char
name|d_short
index|[
literal|2
index|]
typedef|;
end_typedef

begin_if
if|#
directive|if
name|vax
end_if

begin_define
define|#
directive|define
name|D_SHORT
parameter_list|(
name|x
parameter_list|)
value|(*((u_short *)(x)))
end_define

begin_define
define|#
directive|define
name|AD_SHORT
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(*((u_short *)(x))) = (v)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The DECnet code, like the Internet code, runs off software  * interrupts.  At present there is only a software interrupt  * for the NSP layer, which will hand the data to the socket.  */
end_comment

begin_define
define|#
directive|define
name|setnspintr
parameter_list|()
value|mtpr(SIRR, 14)
end_define

begin_define
define|#
directive|define
name|splimp
value|spl5
end_define

end_unit

