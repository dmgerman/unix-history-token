begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* algorithm.h - */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/algorithm.h,v 7.1 91/02/22 09:25:23 mrose Interim $  *  *  * $Log:	algorithm.h,v $  * Revision 7.1  91/02/22  09:25:23  mrose  * Interim 6.8  *   * Revision 7.0  91/01/28  06:26:53  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUALGORITHM
end_ifndef

begin_define
define|#
directive|define
name|QUIPUALGORITHM
end_define

begin_struct
struct|struct
name|PublicKeyAlgorithm
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|IFP
name|encrypt
decl_stmt|;
name|IFP
name|decrypt
decl_stmt|;
name|IFP
name|read_secret
decl_stmt|;
name|IFP
name|write_secret
decl_stmt|;
name|IFP
name|read_public
decl_stmt|;
name|IFP
name|write_public
decl_stmt|;
name|IFP
name|pack_encrypted
decl_stmt|;
name|IFP
name|unpack_encrypted
decl_stmt|;
name|IFP
name|pack_public
decl_stmt|;
name|IFP
name|unpack_public
decl_stmt|;
name|IFP
name|pack_secret
decl_stmt|;
name|IFP
name|unpack_secret
decl_stmt|;
name|IFP
name|get_blocksize
decl_stmt|;
name|IFP
name|free_encrypted
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|HashAlgorithm
block|{
name|char
modifier|*
name|hash_name
decl_stmt|;
name|IFP
name|hash_block
decl_stmt|;
name|IFP
name|hash_short
decl_stmt|;
name|IFP
name|hash_start
decl_stmt|;
name|IFP
name|hash_end
decl_stmt|;
name|IFP
name|hash_pack
decl_stmt|;
name|IFP
name|hash_unpack
decl_stmt|;
name|IFP
name|hash_blocksize
decl_stmt|;
name|IFP
name|hash_compare
decl_stmt|;
name|IFP
name|hash_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|SignatureAlgorithm
block|{
name|char
modifier|*
name|sig_name
decl_stmt|;
name|struct
name|PublicKeyAlgorithm
modifier|*
name|sig_public
decl_stmt|;
name|struct
name|HashAlgorithm
modifier|*
name|sig_hash
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QUIPUALGORITHM */
end_comment

end_unit

