begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Do not modify this file; it is created automatically    by copying.awk.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|immediate_quit
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|copying_info
parameter_list|()
block|{
name|immediate_quit
operator|++
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"		    GNU GENERAL PUBLIC LICENSE\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"		     Version 1, February 1989\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|" Copyright (C) 1989 Free Software Foundation, Inc.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"                    675 Mass Ave, Cambridge, MA 02139, USA\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|" Everyone is permitted to copy and distribute verbatim copies\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|" of this license document, but changing it is not allowed.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"			    Preamble\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  The license agreements of most software companies try to keep users\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"at the mercy of those companies.  By contrast, our General Public\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"License is intended to guarantee your freedom to share and change free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"software--to make sure the software is free for all its users.  The\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"General Public License applies to the Free Software Foundation's\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"software and to any other program whose authors commit to using it.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"You can use it for your programs, too.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  When we speak of free software, we are referring to freedom, not\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"price.  Specifically, the General Public License is designed to make\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"sure that you have the freedom to give away or sell copies of free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"software, that you receive source code or can get it if you want it,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"that you can change the software or use pieces of it in new free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"programs; and that you know you can do these things.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  To protect your rights, we need to make restrictions that forbid\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"anyone to deny you these rights or to ask you to surrender the rights.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"These restrictions translate to certain responsibilities for you if you\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distribute copies of the software, or if you modify it.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  For example, if you distribute copies of a such a program, whether\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"gratis or for a fee, you must give the recipients all the rights that\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"you have.  You must make sure that they, too, receive or can get the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"source code.  And you must tell them their rights.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  We protect your rights with two steps: (1) copyright the software, and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"(2) offer you this license which gives you legal permission to copy,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distribute and/or modify the software.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  Also, for each author's protection and ours, we want to make certain\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"that everyone understands that there is no warranty for this free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"software.  If the software is modified by someone else and passed on, we\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"want its recipients to know that what they have is not the original, so\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"that any problems introduced by others will not reflect on the original\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"authors' reputations.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  The precise terms and conditions for copying, distribution and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"modification follow.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"
literal|\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"		    GNU GENERAL PUBLIC LICENSE\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  0. This License Agreement applies to any program or other work which\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"contains a notice placed by the copyright holder saying it may be\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distributed under the terms of this General Public License.  The\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\"Program\", below, refers to any such program or work, and a \"work based\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"on the Program\" means either the Program or any work containing the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Program or a portion of it, either verbatim or with modifications.  Each\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"licensee is addressed as \"you\".\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  1. You may copy and distribute verbatim copies of the Program's source\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"code as you receive it, in any medium, provided that you conspicuously and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"appropriately publish on each copy an appropriate copyright notice and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"disclaimer of warranty; keep intact all the notices that refer to this\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"General Public License and to the absence of any warranty; and give any\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"other recipients of the Program a copy of this General Public License\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"along with the Program.  You may charge a fee for the physical act of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"transferring a copy.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  2. You may modify your copy or copies of the Program or any portion of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"it, and copy and distribute such modifications under the terms of Paragraph\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"1 above, provided that you also do the following:\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    a) cause the modified files to carry prominent notices stating that\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    you changed the files and the date of any change; and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    b) cause the whole of any work that you distribute or publish, that\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    in whole or in part contains the Program or any part thereof, either\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    with or without modifications, to be licensed at no charge to all\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    third parties under the terms of this General Public License (except\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    that you may choose to grant warranty protection to some or all\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    third parties, at your option).\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    c) If the modified program normally reads commands interactively when\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    run, you must cause it, when started running for such interactive use\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    in the simplest and most usual way, to print or display an\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    announcement including an appropriate copyright notice and a notice\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    that there is no warranty (or else, saying that you provide a\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    warranty) and that users may redistribute the program under these\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    conditions, and telling the user how to view a copy of this General\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    Public License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    d) You may charge a fee for the physical act of transferring a\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    copy, and you may at your option offer warranty protection in\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    exchange for a fee.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Mere aggregation of another independent work with the Program (or its\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"derivative) on a volume of a storage or distribution medium does not bring\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the other work under the scope of these terms.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"
literal|\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  3. You may copy and distribute the Program (or a portion or derivative of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"it, under Paragraph 2) in object code or executable form under the terms of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Paragraphs 1 and 2 above provided that you also do one of the following:\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    a) accompany it with the complete corresponding machine-readable\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    source code, which must be distributed under the terms of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    Paragraphs 1 and 2 above; or,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    b) accompany it with a written offer, valid for at least three\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    years, to give any third party free (except for a nominal charge\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    for the cost of distribution) a complete machine-readable copy of the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    corresponding source code, to be distributed under the terms of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    Paragraphs 1 and 2 above; or,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    c) accompany it with the information you received as to where the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    corresponding source code may be obtained.  (This alternative is\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    allowed only for noncommercial distribution and only if you\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    received the program in object code or executable form alone.)\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Source code for a work means the preferred form of the work for making\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"modifications to it.  For an executable file, complete source code means\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"all the source code for all modules it contains; but, as a special\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"exception, it need not include source code for modules which are standard\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"libraries that accompany the operating system on which the executable\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"file runs, or for standard header files or definitions files that\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"accompany that operating system.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  4. You may not copy, modify, sublicense, distribute or transfer the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Program except as expressly provided under this General Public License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Any attempt otherwise to copy, modify, sublicense, distribute or transfer\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the Program is void, and will automatically terminate your rights to use\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the Program under this License.  However, parties who have received\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"copies, or rights to use copies, from you under this General Public\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"License will not have their licenses terminated so long as such parties\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"remain in full compliance.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  5. By copying, distributing or modifying the Program (or any work based\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"on the Program) you indicate your acceptance of this license to do so,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"and all its terms and conditions.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  6. Each time you redistribute the Program (or any work based on the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Program), the recipient automatically receives a license from the original\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"licensor to copy, distribute or modify the Program subject to these\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"terms and conditions.  You may not impose any further restrictions on the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"recipients' exercise of the rights granted herein.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"
literal|\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  7. The Free Software Foundation may publish revised and/or new versions\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"of the General Public License from time to time.  Such new versions will\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"be similar in spirit to the present version, but may differ in detail to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"address new problems or concerns.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Each version is given a distinguishing version number.  If the Program\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"specifies a version number of the license which applies to it and \"any\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"later version\", you have the option of following the terms and conditions\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"either of that version or of any later version published by the Free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Software Foundation.  If the Program does not specify a version number of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the license, you may choose any version ever published by the Free Software\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Foundation.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  8. If you wish to incorporate parts of the Program into other free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"programs whose distribution conditions are different, write to the author\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"to ask for permission.  For software which is copyrighted by the Free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Software Foundation, write to the Free Software Foundation; we sometimes\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"make exceptions for this.  Our decision will be guided by the two goals\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"of preserving the free status of all derivatives of our free software and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"of promoting the sharing and reuse of software generally.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|immediate_quit
operator|--
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|warranty_info
parameter_list|()
block|{
name|immediate_quit
operator|++
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"			    NO WARRANTY\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  9. BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"REPAIR OR CORRECTION.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  10. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"POSSIBILITY OF SUCH DAMAGES.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|immediate_quit
operator|--
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_initialize_copying
parameter_list|()
block|{
name|add_info
argument_list|(
literal|"copying"
argument_list|,
name|copying_info
argument_list|,
literal|"Conditions for redistributing copies of GDB."
argument_list|)
expr_stmt|;
name|add_info
argument_list|(
literal|"warranty"
argument_list|,
name|warranty_info
argument_list|,
literal|"Various kinds of warranty you do not have."
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

