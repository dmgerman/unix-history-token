begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cpu.h	4.6	81/04/03	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Cpu identification, from SID register.  */
end_comment

begin_union
union|union
name|cpusid
block|{
name|int
name|cpusid
decl_stmt|;
struct|struct
name|cpuany
block|{
name|u_int
label|:
literal|24
operator|,
name|cp_type
operator|:
literal|8
expr_stmt|;
block|}
name|cpuany
struct|;
struct|struct
name|cpu780
block|{
name|u_int
name|cp_sno
range|:
literal|12
decl_stmt|,
comment|/* serial number */
name|cp_plant
range|:
literal|3
decl_stmt|,
comment|/* plant number */
name|cp_eco
range|:
literal|9
decl_stmt|,
comment|/* eco level */
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_780 */
block|}
name|cpu780
struct|;
struct|struct
name|cpu750
block|{
name|u_int
name|cp_hrev
range|:
literal|8
decl_stmt|,
comment|/* hardware rev level */
name|cp_urev
range|:
literal|8
decl_stmt|,
comment|/* ucode rev level */
range|:
literal|8
decl_stmt|,
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_750 */
block|}
name|cpu750
struct|;
comment|/* need structure for 7ZZ */
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VAX_780
value|1
end_define

begin_define
define|#
directive|define
name|VAX_750
value|2
end_define

begin_define
define|#
directive|define
name|VAX_7ZZ
value|3
end_define

begin_define
define|#
directive|define
name|VAX_MAX
value|3
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Per-cpu information for system.  */
end_comment

begin_struct
struct|struct
name|percpu
block|{
name|short
name|pc_cputype
decl_stmt|;
comment|/* cpu type code */
name|short
name|pc_nnexus
decl_stmt|;
comment|/* number of nexus slots */
name|struct
name|nexus
modifier|*
name|pc_nexbase
decl_stmt|;
comment|/* base of nexus space */
comment|/* we should be able to have just one address for the unibus memories */
comment|/* and calculate successive addresses by adding to the base, but the 750 */
comment|/* doesn't obey the sensible rule: uba1 has a lower address than uba0! */
name|caddr_t
modifier|*
name|pc_umaddr
decl_stmt|;
comment|/* unibus memory addresses */
name|short
name|pc_nubabdp
decl_stmt|;
comment|/* number of bdp's per uba */
name|short
name|pc_haveubasr
decl_stmt|;
comment|/* have uba status register */
comment|/* the 750 has some slots which don't promise to tell you their types */
comment|/* if this pointer is non-zero, then you get the type from this array */
comment|/* rather than from the (much more sensible) low byte of the config register */
name|short
modifier|*
name|pc_nextype
decl_stmt|;
comment|/* botch */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|percpu
name|percpu
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

