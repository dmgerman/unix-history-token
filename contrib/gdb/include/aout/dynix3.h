begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * a.out specifics for Sequent Symmetry running Dynix 3.x  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|A_OUT_DYNIX3_H
end_ifndef

begin_define
define|#
directive|define
name|A_OUT_DYNIX3_H
end_define

begin_define
define|#
directive|define
name|external_exec
value|dynix_external_exec
end_define

begin_comment
comment|/* struct exec for Dynix 3  *  * a_gdtbl and a_bootstrap are only for standalone binaries.  * Shared data fields are not supported by the kernel as of Dynix 3.1,  * but are supported by Dynix compiler programs.  */
end_comment

begin_struct
struct|struct
name|dynix_external_exec
block|{
name|unsigned
name|char
name|e_info
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_text
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_data
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_bss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_syms
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_entry
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_trsize
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_drsize
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_g_code
index|[
literal|8
index|]
decl_stmt|,
name|e_g_data
index|[
literal|8
index|]
decl_stmt|,
name|e_g_desc
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|e_shdata
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_shbss
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_shdrsize
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_bootstrap
index|[
literal|44
index|]
decl_stmt|;
name|unsigned
name|char
name|e_reserved
index|[
literal|12
index|]
decl_stmt|;
name|unsigned
name|char
name|e_version
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXEC_BYTES_SIZE
value|(128)
end_define

begin_comment
comment|/*  * All executables under Dynix are demand paged with read-only text,  * Thus no NMAGIC.  *  * ZMAGIC has a page of 0s at virtual 0,  * XMAGIC has an invalid page at virtual 0  */
end_comment

begin_define
define|#
directive|define
name|OMAGIC
value|0x12eb
end_define

begin_comment
comment|/* .o */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0x22eb
end_define

begin_comment
comment|/* zero @ 0, demand load */
end_comment

begin_define
define|#
directive|define
name|XMAGIC
value|0x32eb
end_define

begin_comment
comment|/* invalid @ 0, demand load */
end_comment

begin_define
define|#
directive|define
name|SMAGIC
value|0x42eb
end_define

begin_comment
comment|/* standalone, not supported here */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|((OMAGIC != N_MAGIC(x))&& \ 		     (ZMAGIC != N_MAGIC(x))&& \ 		     (XMAGIC != N_MAGIC(x))&& \ 		     (SMAGIC != N_MAGIC(x)))
end_define

begin_define
define|#
directive|define
name|N_ADDRADJ
parameter_list|(
name|x
parameter_list|)
value|((ZMAGIC == N_MAGIC(x) || XMAGIC == N_MAGIC(x)) ? 0x1000 : 0)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|(EXEC_BYTES_SIZE)
end_define

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|x
parameter_list|)
value|(N_TXTOFF(x) + N_TXTSIZE(x))
end_define

begin_define
define|#
directive|define
name|N_SHDATOFF
parameter_list|(
name|x
parameter_list|)
value|(N_DATOFF(x) + (x).a_data)
end_define

begin_define
define|#
directive|define
name|N_TRELOFF
parameter_list|(
name|x
parameter_list|)
value|(N_SHDATOFF(x) + (x).a_shdata)
end_define

begin_define
define|#
directive|define
name|N_DRELOFF
parameter_list|(
name|x
parameter_list|)
value|(N_TRELOFF(x) + (x).a_trsize)
end_define

begin_define
define|#
directive|define
name|N_SHDRELOFF
parameter_list|(
name|x
parameter_list|)
value|(N_DRELOFF(x) + (x).a_drsize)
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|(N_SHDRELOFF(x) + (x).a_shdrsize)
end_define

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|x
parameter_list|)
value|(N_SYMOFF(x) + (x).a_syms)
end_define

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((OMAGIC == N_MAGIC(x)) || (SMAGIC == N_MAGIC(x))) ? 0 \ 	 : TEXT_START_ADDR + EXEC_BYTES_SIZE)
end_define

begin_define
define|#
directive|define
name|N_TXTSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((OMAGIC == N_MAGIC(x)) || (SMAGIC == N_MAGIC(x))) ? ((x).a_text) \ 	 : ((x).a_text - N_ADDRADJ(x) - EXEC_BYTES_SIZE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A_OUT_DYNIX3_H */
end_comment

end_unit

