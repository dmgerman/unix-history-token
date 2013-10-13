begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: umac.h,v 1.3 2013/07/22 12:20:02 djm Exp $ */
end_comment

begin_comment
comment|/* -----------------------------------------------------------------------  *   * umac.h -- C Implementation UMAC Message Authentication  *  * Version 0.93a of rfc4418.txt -- 2006 July 14  *  * For a full description of UMAC message authentication see the UMAC  * world-wide-web page at http://www.cs.ucdavis.edu/~rogaway/umac  * Please report bugs and suggestions to the UMAC webpage.  *  * Copyright (c) 1999-2004 Ted Krovetz  *                                                                   * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and with or without fee, is hereby  * granted provided that the above copyright notice appears in all copies  * and in supporting documentation, and that the name of the copyright  * holder not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior permission.  *  * Comments should be directed to Ted Krovetz (tdk@acm.org)                                          *                                                                     * ---------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* ////////////////////// IMPORTANT NOTES /////////////////////////////////   *   * 1) This version does not work properly on messages larger than 16MB   *   * 2) If you set the switch to use SSE2, then all data must be 16-byte   *    aligned   *   * 3) When calling the function umac(), it is assumed that msg is in   * a writable buffer of length divisible by 32 bytes. The message itself   * does not have to fill the entire buffer, but bytes beyond msg may be   * zeroed.   *   * 4) Two free AES implementations are supported by this implementation of   * UMAC. Paulo Barreto's version is in the public domain and can be found   * at http://www.esat.kuleuven.ac.be/~rijmen/rijndael/ (search for   * "Barreto"). The only two files needed are rijndael-alg-fst.c and   * rijndael-alg-fst.h.   * Brian Gladman's version is distributed with GNU Public lisence   * and can be found at http://fp.gladman.plus.com/AES/index.htm. It   * includes a fast IA-32 assembly version.   *   /////////////////////////////////////////////////////////////////////// */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_UMAC_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_UMAC_H
end_define

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
name|struct
name|umac_ctx
modifier|*
name|umac_new
parameter_list|(
specifier|const
name|u_char
name|key
index|[]
parameter_list|)
function_decl|;
comment|/* Dynamically allocate a umac_ctx struct, initialize variables,   * generate subkeys from key.  */
if|#
directive|if
literal|0
block|int umac_reset(struct umac_ctx *ctx);
comment|/* Reset a umac_ctx to begin authenicating a new message */
endif|#
directive|endif
name|int
name|umac_update
parameter_list|(
name|struct
name|umac_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u_char
modifier|*
name|input
parameter_list|,
name|long
name|len
parameter_list|)
function_decl|;
comment|/* Incorporate len bytes pointed to by input into context ctx */
name|int
name|umac_final
parameter_list|(
name|struct
name|umac_ctx
modifier|*
name|ctx
parameter_list|,
name|u_char
name|tag
index|[]
parameter_list|,
specifier|const
name|u_char
name|nonce
index|[
literal|8
index|]
parameter_list|)
function_decl|;
comment|/* Incorporate any pending data and the ctr value, and return tag.   * This function returns error code if ctr< 0.   */
name|int
name|umac_delete
parameter_list|(
name|struct
name|umac_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/* Deallocate the context structure */
if|#
directive|if
literal|0
block|int umac(struct umac_ctx *ctx, u_char *input,           long len, u_char tag[],          u_char nonce[8]);
comment|/* All-in-one implementation of the functions Reset, Update and Final */
endif|#
directive|endif
comment|/* uhash.h */
if|#
directive|if
literal|0
block|typedef struct uhash_ctx *uhash_ctx_t;
comment|/* The uhash_ctx structure is defined by the implementation of the    */
comment|/* UHASH functions.                                                   */
block|uhash_ctx_t uhash_alloc(u_char key[16]);
comment|/* Dynamically allocate a uhash_ctx struct and generate subkeys using */
comment|/* the kdf and kdf_key passed in. If kdf_key_len is 0 then RC6 is     */
comment|/* used to generate key with a fixed key. If kdf_key_len> 0 but kdf  */
comment|/* is NULL then the first 16 bytes pointed at by kdf_key is used as a */
comment|/* key for an RC6 based KDF.                                          */
block|int uhash_free(uhash_ctx_t ctx);  int uhash_set_params(uhash_ctx_t ctx,                    void       *params);  int uhash_reset(uhash_ctx_t ctx);  int uhash_update(uhash_ctx_t ctx,                u_char       *input,                long        len);  int uhash_final(uhash_ctx_t ctx,               u_char        ouput[]);  int uhash(uhash_ctx_t ctx,         u_char       *input,         long        len,         u_char        output[]);
endif|#
directive|endif
comment|/* matching umac-128 API, we reuse umac_ctx, since it's opaque */
name|struct
name|umac_ctx
modifier|*
name|umac128_new
parameter_list|(
specifier|const
name|u_char
name|key
index|[]
parameter_list|)
function_decl|;
name|int
name|umac128_update
parameter_list|(
name|struct
name|umac_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u_char
modifier|*
name|input
parameter_list|,
name|long
name|len
parameter_list|)
function_decl|;
name|int
name|umac128_final
parameter_list|(
name|struct
name|umac_ctx
modifier|*
name|ctx
parameter_list|,
name|u_char
name|tag
index|[]
parameter_list|,
specifier|const
name|u_char
name|nonce
index|[
literal|8
index|]
parameter_list|)
function_decl|;
name|int
name|umac128_delete
parameter_list|(
name|struct
name|umac_ctx
modifier|*
name|ctx
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEADER_UMAC_H */
end_comment

end_unit

