begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Core file stuff.  At least some, perhaps all, of the following    defines work on many more systems than just SCO.  */
end_comment

begin_define
define|#
directive|define
name|NBPG
value|NBPC
end_define

begin_define
define|#
directive|define
name|UPAGES
value|USIZE
end_define

begin_define
define|#
directive|define
name|HOST_DATA_START_ADDR
value|u.u_exdata.ux_datorg
end_define

begin_define
define|#
directive|define
name|HOST_STACK_START_ADDR
value|u.u_sub
end_define

begin_define
define|#
directive|define
name|TRAD_UNIX_CORE_FILE_FAILING_SIGNAL
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((core_upage(abfd)->u_sysabort != 0) \    ? core_upage(abfd)->u_sysabort \    : -1)
end_define

begin_comment
comment|/* According to the manpage, a version 2 SCO corefile can contain    various additional sections (it is cleverly arranged so the u area,    data, and stack are first where we can find them).  So without    writing lots of code to parse all their headers and stuff, we can't    know whether a corefile is bigger than it should be.  */
end_comment

begin_define
define|#
directive|define
name|TRAD_CORE_ALLOW_ANY_EXTRA_SIZE
value|1
end_define

end_unit

