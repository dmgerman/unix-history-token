begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Lookup table for code-to-text translations.  */
end_comment

begin_struct
struct|struct
name|amr_code_lookup
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|u_int32_t
name|code
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|char
modifier|*
name|amr_describe_code
parameter_list|(
name|struct
name|amr_code_lookup
modifier|*
name|table
parameter_list|,
name|u_int32_t
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|AMR_DEFINE_TABLES
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|amr_code_lookup
name|amr_table_qinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|amr_code_lookup
name|amr_table_sinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|amr_code_lookup
name|amr_table_drvstate
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* AMR_DEFINE_TABLES */
end_comment

begin_comment
comment|/********************************************************************************  * Look up a text description of a numeric code and return a pointer to same.  */
end_comment

begin_function
name|char
modifier|*
name|amr_describe_code
parameter_list|(
name|struct
name|amr_code_lookup
modifier|*
name|table
parameter_list|,
name|u_int32_t
name|code
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|table
index|[
name|i
index|]
operator|.
name|string
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|table
index|[
name|i
index|]
operator|.
name|code
operator|==
name|code
condition|)
return|return
operator|(
name|table
index|[
name|i
index|]
operator|.
name|string
operator|)
return|;
return|return
operator|(
name|table
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|string
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|amr_code_lookup
name|amr_table_qinit
index|[]
init|=
block|{
block|{
literal|"init scanning drives"
block|,
name|AMR_QINIT_SCAN
block|}
block|,
block|{
literal|"init scanning initialising"
block|,
name|AMR_QINIT_SCANINIT
block|}
block|,
block|{
literal|"init firmware initing"
block|,
name|AMR_QINIT_FIRMWARE
block|}
block|,
block|{
literal|"init in progress"
block|,
name|AMR_QINIT_INPROG
block|}
block|,
block|{
literal|"init spinning drives"
block|,
name|AMR_QINIT_SPINUP
block|}
block|,
block|{
literal|"insufficient memory"
block|,
name|AMR_QINIT_NOMEM
block|}
block|,
block|{
literal|"init flushing cache"
block|,
name|AMR_QINIT_CACHEFLUSH
block|}
block|,
block|{
literal|"init successfully done"
block|,
name|AMR_QINIT_DONE
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown init code"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|amr_code_lookup
name|amr_table_sinit
index|[]
init|=
block|{
block|{
literal|"init abnormal terminated"
block|,
name|AMR_SINIT_ABEND
block|}
block|,
block|{
literal|"insufficient memory"
block|,
name|AMR_SINIT_NOMEM
block|}
block|,
block|{
literal|"firmware flushing cache"
block|,
name|AMR_SINIT_CACHEFLUSH
block|}
block|,
block|{
literal|"init in progress"
block|,
name|AMR_SINIT_INPROG
block|}
block|,
block|{
literal|"firmware spinning drives"
block|,
name|AMR_SINIT_SPINUP
block|}
block|,
block|{
literal|"init successfully done"
block|,
name|AMR_SINIT_DONE
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown init code"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|amr_code_lookup
name|amr_table_drvstate
index|[]
init|=
block|{
block|{
literal|"offline"
block|,
name|AMR_DRV_OFFLINE
block|}
block|,
block|{
literal|"degraded"
block|,
name|AMR_DRV_DEGRADED
block|}
block|,
block|{
literal|"optimal"
block|,
name|AMR_DRV_OPTIMAL
block|}
block|,
block|{
literal|"online"
block|,
name|AMR_DRV_ONLINE
block|}
block|,
block|{
literal|"failed"
block|,
name|AMR_DRV_FAILED
block|}
block|,
block|{
literal|"rebuild"
block|,
name|AMR_DRV_REBUILD
block|}
block|,
block|{
literal|"hot spare"
block|,
name|AMR_DRV_HOTSPARE
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|amr_code_lookup
name|amr_table_adaptertype
index|[]
init|=
block|{
block|{
literal|"Series 431"
block|,
name|AMR_SIG_431
block|}
block|,
block|{
literal|"Series 438"
block|,
name|AMR_SIG_438
block|}
block|,
block|{
literal|"Series 762"
block|,
name|AMR_SIG_762
block|}
block|,
block|{
literal|"Integrated HP NetRAID (T5)"
block|,
name|AMR_SIG_T5
block|}
block|,
block|{
literal|"Series 466"
block|,
name|AMR_SIG_466
block|}
block|,
block|{
literal|"Series 467"
block|,
name|AMR_SIG_467
block|}
block|,
block|{
literal|"Integrated HP NetRAID (T7)"
block|,
name|AMR_SIG_T7
block|}
block|,
block|{
literal|"Series 490"
block|,
name|AMR_SIG_490
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown adapter"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

