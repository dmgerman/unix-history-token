begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dkuug.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_INFLATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_INFLATE_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KZIP
argument_list|)
end_if

begin_define
define|#
directive|define
name|GZ_EOF
value|-1
end_define

begin_define
define|#
directive|define
name|GZ_WSIZE
value|0x8000
end_define

begin_comment
comment|/*  * Global variables used by inflate and friends.  * This structure is used in order to make inflate() reentrant.  */
end_comment

begin_struct
struct|struct
name|inflate
block|{
comment|/* Public part */
comment|/* This pointer is passed along to the two functions below */
name|void
modifier|*
name|gz_private
decl_stmt|;
comment|/* Fetch next character to be uncompressed */
name|int
argument_list|(
argument|*gz_input
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Dispose of uncompressed characters */
name|int
argument_list|(
argument|*gz_output
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_long
operator|)
argument_list|)
expr_stmt|;
comment|/* Private part */
name|u_long
name|gz_bb
decl_stmt|;
comment|/* bit buffer */
name|unsigned
name|gz_bk
decl_stmt|;
comment|/* bits in bit buffer */
name|unsigned
name|gz_hufts
decl_stmt|;
comment|/* track memory usage */
name|struct
name|huft
modifier|*
name|gz_fixed_tl
decl_stmt|;
comment|/* must init to NULL !! */
name|struct
name|huft
modifier|*
name|gz_fixed_td
decl_stmt|;
name|int
name|gz_fixed_bl
decl_stmt|;
name|int
name|gz_fixed_bd
decl_stmt|;
name|u_char
modifier|*
name|gz_slide
decl_stmt|;
name|unsigned
name|gz_wp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|inflate
name|__P
argument_list|(
operator|(
expr|struct
name|inflate
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL || KZIP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SYS_INFLATE_H_ */
end_comment

end_unit

