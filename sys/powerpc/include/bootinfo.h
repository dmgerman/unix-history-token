begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Kernel-internal structure used to hold important bits of boot  * information.  NOT to be used by boot blocks.  *  * Note that not all of the fields from the bootinfo struct(s)  * passed by the boot blocks aren't here (because they're not currently  * used by the kernel!).  Fields here which aren't supplied by the  * bootinfo structure passed by the boot blocks are supposed to be  * filled in at startup with sane contents.  */
end_comment

begin_struct
struct|struct
name|bootinfo_kernel
block|{
name|u_long
name|ssym
decl_stmt|;
comment|/* start of syms */
name|u_long
name|esym
decl_stmt|;
comment|/* end of syms */
name|u_long
name|hwrpb_phys
decl_stmt|;
comment|/* hwrpb physical address */
name|u_long
name|hwrpb_size
decl_stmt|;
comment|/* size of hwrpb data */
name|char
name|boot_flags
index|[
literal|64
index|]
decl_stmt|;
comment|/* boot flags */
name|char
name|booted_kernel
index|[
literal|64
index|]
decl_stmt|;
comment|/* name of booted kernel */
name|char
name|booted_dev
index|[
literal|64
index|]
decl_stmt|;
comment|/* name of booted device */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo_kernel
name|bootinfo
decl_stmt|;
end_decl_stmt

end_unit

