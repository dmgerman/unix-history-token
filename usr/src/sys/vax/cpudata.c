begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cpudata.c	6.1	83/07/29	*/
end_comment

begin_include
include|#
directive|include
file|"../machine/pte.h"
end_include

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../vax/cpu.h"
end_include

begin_include
include|#
directive|include
file|"../vax/nexus.h"
end_include

begin_include
include|#
directive|include
file|"../vaxuba/ubareg.h"
end_include

begin_comment
comment|/*  * Initialization of per-cpu data structures.  */
end_comment

begin_comment
comment|/*  * These are the (fixed) addresses of the (last 8k bytes of)  * unibus memory for each of the possible unibus adapters.  Note that the  * unibus memory addresses are actually indexed by the unibus adapter type code.  */
end_comment

begin_if
if|#
directive|if
name|VAX780
end_if

begin_decl_stmt
name|caddr_t
name|umaddr780
index|[
literal|4
index|]
init|=
block|{
operator|(
name|caddr_t
operator|)
name|UMEM780
argument_list|(
literal|0
argument_list|)
block|,
operator|(
name|caddr_t
operator|)
name|UMEM780
argument_list|(
literal|1
argument_list|)
block|,
operator|(
name|caddr_t
operator|)
name|UMEM780
argument_list|(
literal|2
argument_list|)
block|,
operator|(
name|caddr_t
operator|)
name|UMEM780
argument_list|(
literal|3
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX750
end_if

begin_decl_stmt
name|caddr_t
name|umaddr750
index|[
literal|2
index|]
init|=
block|{
operator|(
name|caddr_t
operator|)
name|UMEM750
argument_list|(
literal|0
argument_list|)
block|,
operator|(
name|caddr_t
operator|)
name|UMEM750
argument_list|(
literal|1
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX730
end_if

begin_decl_stmt
name|caddr_t
name|umaddr730
index|[
literal|1
index|]
init|=
block|{
operator|(
name|caddr_t
operator|)
name|UMEM730
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Information to patch around the stupidity of configuration  * registers not returning types on some of the processors.  */
end_comment

begin_if
if|#
directive|if
name|VAX750
end_if

begin_decl_stmt
name|short
name|nexty750
index|[
name|NNEX750
index|]
init|=
block|{
name|NEX_MEM16
block|,
name|NEX_MEM16
block|,
name|NEX_MEM16
block|,
name|NEX_MEM16
block|,
name|NEX_MBA
block|,
name|NEX_MBA
block|,
name|NEX_MBA
block|,
name|NEX_MBA
block|,
name|NEX_UBA0
block|,
name|NEX_UBA1
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX730
end_if

begin_decl_stmt
name|short
name|nexty730
index|[
name|NNEX730
index|]
init|=
block|{
name|NEX_MEM16
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|,
name|NEX_ANY
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|percpu
name|percpu
index|[]
init|=
block|{
if|#
directive|if
name|VAX780
name|VAX_780
block|,
name|NNEX780
block|,
name|NEX780
block|,
name|umaddr780
block|,
name|NBDP780
block|,
literal|1
block|,
literal|0
block|,
endif|#
directive|endif
if|#
directive|if
name|VAX750
name|VAX_750
block|,
name|NNEX750
block|,
name|NEX750
block|,
name|umaddr750
block|,
name|NBDP750
block|,
literal|0
block|,
name|nexty750
block|,
endif|#
directive|endif
if|#
directive|if
name|VAX730
name|VAX_730
block|,
name|NNEX730
block|,
name|NEX730
block|,
name|umaddr730
block|,
name|NBDP730
block|,
literal|0
block|,
name|nexty730
block|,
endif|#
directive|endif
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

