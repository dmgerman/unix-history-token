begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NetBSD: cast128.h,v 1.6 2003/08/26 20:03:57 thorpej Exp $ */
end_comment

begin_comment
comment|/*      $OpenBSD: cast.h,v 1.2 2002/03/14 01:26:51 millert Exp $       */
end_comment

begin_comment
comment|/*  *	CAST-128 in C  *	Written by Steve Reid<sreid@sea-to-sky.net>  *	100% Public Domain - no warranty  *	Released 1997.10.11  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAST128_H_
end_ifndef

begin_define
define|#
directive|define
name|_CAST128_H_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|xkey
index|[
literal|32
index|]
decl_stmt|;
comment|/* Key, after expansion */
name|int
name|rounds
decl_stmt|;
comment|/* Number of rounds to use, 12 or 16 */
block|}
name|cast128_key
typedef|;
end_typedef

begin_function_decl
name|void
name|cast128_setkey
parameter_list|(
name|cast128_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|rawkey
parameter_list|,
name|int
name|keybytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cast128_encrypt
parameter_list|(
specifier|const
name|cast128_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|inblock
parameter_list|,
name|u_int8_t
modifier|*
name|outblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cast128_decrypt
parameter_list|(
specifier|const
name|cast128_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|inblock
parameter_list|,
name|u_int8_t
modifier|*
name|outblock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAST128_H_ */
end_comment

end_unit

