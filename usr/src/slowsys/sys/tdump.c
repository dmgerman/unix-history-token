begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Dump core to magtape  * Assumes memory mapping has been disabled  * and IPL has be set high (> 0x15 )  */
end_comment

begin_define
define|#
directive|define
name|PHYSPAGES
value|1024
end_define

begin_define
define|#
directive|define
name|UBA
value|0x20006000
end_define

begin_define
define|#
directive|define
name|mba0
value|0x20010000
end_define

begin_define
define|#
directive|define
name|mba1
value|0x20012000
end_define

begin_struct
struct|struct
name|mba_regs
block|{
name|int
name|mba_csr
decl_stmt|,
name|mba_cr
decl_stmt|,
name|mba_sr
decl_stmt|,
name|mba_var
decl_stmt|,
name|mba_bcr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|device
block|{
name|int
name|htcs1
decl_stmt|;
name|int
name|htds
decl_stmt|;
name|int
name|hter
decl_stmt|;
name|int
name|htmr
decl_stmt|;
name|int
name|htas
decl_stmt|;
name|int
name|htfc
decl_stmt|;
name|int
name|htdt
decl_stmt|;
name|int
name|htck
decl_stmt|;
name|int
name|htsn
decl_stmt|;
name|int
name|httc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HTADDR
value|((struct device *)(mba1 + 0x400))
end_define

begin_define
define|#
directive|define
name|HTMAP
value|((int *) (mba1 + 0x800))
end_define

begin_define
define|#
directive|define
name|GO
value|01
end_define

begin_define
define|#
directive|define
name|WCOM
value|060
end_define

begin_define
define|#
directive|define
name|RCOM
value|070
end_define

begin_define
define|#
directive|define
name|NOP
value|0
end_define

begin_define
define|#
directive|define
name|WEOF
value|026
end_define

begin_define
define|#
directive|define
name|SFORW
value|030
end_define

begin_define
define|#
directive|define
name|SREV
value|032
end_define

begin_define
define|#
directive|define
name|ERASE
value|024
end_define

begin_define
define|#
directive|define
name|REW
value|06
end_define

begin_define
define|#
directive|define
name|DCLR
value|010
end_define

begin_define
define|#
directive|define
name|P800
value|01300
end_define

begin_comment
comment|/* 800 + pdp11 mode */
end_comment

begin_define
define|#
directive|define
name|P1600
value|02300
end_define

begin_comment
comment|/* 1600 + pdp11 mode */
end_comment

begin_define
define|#
directive|define
name|IENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|RDY
value|0200
end_define

begin_define
define|#
directive|define
name|TM
value|04
end_define

begin_define
define|#
directive|define
name|DRY
value|0200
end_define

begin_define
define|#
directive|define
name|EOT
value|02000
end_define

begin_define
define|#
directive|define
name|CS
value|02000
end_define

begin_define
define|#
directive|define
name|COR
value|0100000
end_define

begin_define
define|#
directive|define
name|PES
value|040
end_define

begin_define
define|#
directive|define
name|WRL
value|04000
end_define

begin_define
define|#
directive|define
name|MOL
value|010000
end_define

begin_define
define|#
directive|define
name|ERR
value|040000
end_define

begin_define
define|#
directive|define
name|FCE
value|01000
end_define

begin_define
define|#
directive|define
name|TRE
value|040000
end_define

begin_define
define|#
directive|define
name|HARD
value|064023
end_define

begin_comment
comment|/* UNS|OPI|NEF|FMT|RMR|ILR|ILF */
end_comment

begin_define
define|#
directive|define
name|SIO
value|1
end_define

begin_define
define|#
directive|define
name|SSFOR
value|2
end_define

begin_define
define|#
directive|define
name|SSREV
value|3
end_define

begin_define
define|#
directive|define
name|SRETRY
value|4
end_define

begin_define
define|#
directive|define
name|SCOM
value|5
end_define

begin_define
define|#
directive|define
name|SOK
value|6
end_define

begin_macro
name|dump
argument_list|()
end_macro

begin_block
block|{
name|HTADDR
operator|->
name|httc
operator|=
name|P800
expr_stmt|;
comment|/* set 800 bpi mode */
name|twall
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|PHYSPAGES
argument_list|)
expr_stmt|;
comment|/* write out memory */
name|teof
argument_list|()
expr_stmt|;
name|teof
argument_list|()
expr_stmt|;
name|rewind
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|twall
argument_list|(
argument|start
argument_list|,
argument|num
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|num
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|HTADDR
operator|->
name|htcs1
operator|=
name|DCLR
operator||
name|GO
expr_stmt|;
while|while
condition|(
name|num
operator|--
condition|)
block|{
name|twrite
argument_list|(
name|start
argument_list|)
expr_stmt|;
name|start
operator|+=
literal|512
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|twrite
argument_list|(
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|twait
argument_list|()
expr_stmt|;
name|HTADDR
operator|->
name|htfc
operator|=
operator|-
literal|512
expr_stmt|;
operator|*
name|HTMAP
operator|=
operator|(
operator|(
operator|(
name|int
operator|)
name|buf
operator|)
operator|>>
literal|9
operator|)
operator||
literal|0x80000000
expr_stmt|;
comment|/* map entry */
operator|(
operator|(
expr|struct
name|mba_regs
operator|*
operator|)
name|mba1
operator|)
operator|->
name|mba_sr
operator|=
operator|-
literal|1
expr_stmt|;
operator|(
operator|(
expr|struct
name|mba_regs
operator|*
operator|)
name|mba1
operator|)
operator|->
name|mba_bcr
operator|=
operator|-
literal|512
expr_stmt|;
operator|(
operator|(
expr|struct
name|mba_regs
operator|*
operator|)
name|mba1
operator|)
operator|->
name|mba_var
operator|=
literal|0
expr_stmt|;
name|HTADDR
operator|->
name|htcs1
operator|=
name|WCOM
operator||
name|GO
expr_stmt|;
return|return;
block|}
end_block

begin_macro
name|twait
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|s
expr_stmt|;
do|do
name|s
operator|=
name|HTADDR
operator|->
name|htds
expr_stmt|;
do|while
condition|(
operator|(
name|s
operator|&
name|RDY
operator|)
operator|==
literal|0
condition|)
do|;
block|}
end_block

begin_macro
name|rewind
argument_list|()
end_macro

begin_block
block|{
name|twait
argument_list|()
expr_stmt|;
name|HTADDR
operator|->
name|htcs1
operator|=
name|REW
operator||
name|GO
expr_stmt|;
block|}
end_block

begin_macro
name|teof
argument_list|()
end_macro

begin_block
block|{
name|twait
argument_list|()
expr_stmt|;
name|HTADDR
operator|->
name|htcs1
operator|=
name|WEOF
operator||
name|GO
expr_stmt|;
block|}
end_block

end_unit

