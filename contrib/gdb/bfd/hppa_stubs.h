begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HPPA linker stub instructions  */
end_comment

begin_comment
comment|/* These are the instructions which the linker may insert into the    code stream when building final executables to handle out-of-range    calls and argument relocations.  */
end_comment

begin_define
define|#
directive|define
name|LDO_M4_R31_R31
value|0x37ff3ff9
end_define

begin_comment
comment|/* ldo -4(%r31),%r31	  */
end_comment

begin_define
define|#
directive|define
name|LDIL_R1
value|0x20200000
end_define

begin_comment
comment|/* ldil XXX,%r1		  */
end_comment

begin_define
define|#
directive|define
name|BE_SR4_R1
value|0xe0202000
end_define

begin_comment
comment|/* be XXX(%sr4,%r1)	  */
end_comment

begin_define
define|#
directive|define
name|COPY_R31_R2
value|0x081f0242
end_define

begin_comment
comment|/* copy %r31,%r2	  */
end_comment

begin_define
define|#
directive|define
name|BLE_SR4_R0
value|0xe4002000
end_define

begin_comment
comment|/* ble XXX(%sr4,%r0)	  */
end_comment

begin_define
define|#
directive|define
name|BLE_SR4_R1
value|0xe4202000
end_define

begin_comment
comment|/* ble XXX(%sr4,%r1)	  */
end_comment

begin_define
define|#
directive|define
name|BV_N_0_R31
value|0xebe0c002
end_define

begin_comment
comment|/* bv,n 0(%r31)		  */
end_comment

begin_define
define|#
directive|define
name|STW_R31_M8R30
value|0x6bdf3ff1
end_define

begin_comment
comment|/* stw %r31,-8(%r30)	  */
end_comment

begin_define
define|#
directive|define
name|LDW_M8R30_R31
value|0x4bdf3ff1
end_define

begin_comment
comment|/* ldw -8(%r30),%r31	  */
end_comment

begin_define
define|#
directive|define
name|STW_ARG_M16R30
value|0x6bc03fe1
end_define

begin_comment
comment|/* stw %argX,-16(%r30)	  */
end_comment

begin_define
define|#
directive|define
name|LDW_M16R30_ARG
value|0x4bc03fe1
end_define

begin_comment
comment|/* ldw -12(%r30),%argX	  */
end_comment

begin_define
define|#
directive|define
name|STW_ARG_M12R30
value|0x6bc03fe9
end_define

begin_comment
comment|/* stw %argX,-16(%r30)	  */
end_comment

begin_define
define|#
directive|define
name|LDW_M12R30_ARG
value|0x4bc03fe9
end_define

begin_comment
comment|/* ldw -12(%r30),%argX	  */
end_comment

begin_define
define|#
directive|define
name|FSTW_FARG_M16R30
value|0x27c11200
end_define

begin_comment
comment|/* fstws %fargX,-16(%r30) */
end_comment

begin_define
define|#
directive|define
name|FLDW_M16R30_FARG
value|0x27c11000
end_define

begin_comment
comment|/* fldws -16(%r30),%fargX */
end_comment

begin_define
define|#
directive|define
name|FSTD_FARG_M16R30
value|0x2fc11200
end_define

begin_comment
comment|/* fstds %fargX,-16(%r30) */
end_comment

begin_define
define|#
directive|define
name|FLDD_M16R30_FARG
value|0x2fc11000
end_define

begin_comment
comment|/* fldds -16(%r30),%fargX */
end_comment

end_unit

