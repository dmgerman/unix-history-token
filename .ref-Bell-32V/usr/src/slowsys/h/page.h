begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   VAX page table entry  */
end_comment

begin_struct
struct|struct
name|pt_entry
block|{
name|int
name|pg_pfnum
range|:
literal|21
decl_stmt|,
range|:
literal|2
decl_stmt|,
name|pg_type
range|:
literal|2
decl_stmt|,
range|:
literal|1
decl_stmt|,
name|pg_m
range|:
literal|1
decl_stmt|,
name|pg_prot
range|:
literal|4
decl_stmt|,
name|pg_v
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PG_PFNUM
value|0x1fffff
end_define

begin_define
define|#
directive|define
name|PG_M
value|0x4000000
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|0x78000000
end_define

begin_define
define|#
directive|define
name|PG_V
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PG_NOACC
value|0
end_define

begin_define
define|#
directive|define
name|PG_KR
value|0x18000000
end_define

begin_define
define|#
directive|define
name|PG_KW
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PG_UW
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PGURKW
value|0x60000000
end_define

begin_define
define|#
directive|define
name|PG_URKR
value|0x78000000
end_define

begin_define
define|#
directive|define
name|PG_TXT
value|0x01800000
end_define

end_unit

