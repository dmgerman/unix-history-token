begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==> Do not modify this file!!  It is created automatically    by copying.awk.  Modify copying.awk instead.<== */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"gdbcmd.h"
end_include

begin_decl_stmt
specifier|static
name|void
name|show_copying_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|show_warranty_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_initialize_copying
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|immediate_quit
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|show_copying_command
parameter_list|(
name|ignore
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|ignore
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|immediate_quit
operator|++
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"		    GNU GENERAL PUBLIC LICENSE\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"		       Version 2, June 1991\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|" Copyright (C) 1989, 1991 Free Software Foundation, Inc.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"                       59 Temple Place, Suite 330, Boston, MA  02111-1307  USA\n"
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
literal|"  The licenses for most software are designed to take away your\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"freedom to share and change it.  By contrast, the GNU General Public\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"License is intended to guarantee your freedom to share and change free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"software--to make sure the software is free for all its users.  This\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"General Public License applies to most of the Free Software\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Foundation's software and to any other program whose authors commit to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"using it.  (Some other Free Software Foundation software is covered by\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the GNU Library General Public License instead.)  You can apply it to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"your programs, too.\n"
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
literal|"price.  Our General Public Licenses are designed to make sure that you\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"have the freedom to distribute copies of free software (and charge for\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"this service if you wish), that you receive source code or can get it\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"if you want it, that you can change the software or use pieces of it\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"in new free programs; and that you know you can do these things.\n"
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
literal|"  For example, if you distribute copies of such a program, whether\n"
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
literal|"source code.  And you must show them these terms so they know their\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"rights.\n"
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
literal|"  Finally, any free program is threatened constantly by software\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"patents.  We wish to avoid the danger that redistributors of a free\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"program will individually obtain patent licenses, in effect making the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"program proprietary.  To prevent this, we have made it clear that any\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"patent must be licensed for everyone's free use or not licensed at all.\n"
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
literal|"  0. This License applies to any program or other work which contains\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"a notice placed by the copyright holder saying it may be distributed\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"under the terms of this General Public License.  The \"Program\", below,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"refers to any such program or work, and a \"work based on the Program\"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"means either the Program or any derivative work under copyright law:\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"that is to say, a work containing the Program or a portion of it,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"either verbatim or with modifications and/or translated into another\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"language.  (Hereinafter, translation is included without limitation in\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the term \"modification\".)  Each licensee is addressed as \"you\".\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Activities other than copying, distribution and modification are not\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"covered by this License; they are outside its scope.  The act of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"running the Program is not restricted, and the output from the Program\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"is covered only if its contents constitute a work based on the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Program (independent of having been made by running the Program).\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Whether that is true depends on what the Program does.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  1. You may copy and distribute verbatim copies of the Program's\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"source code as you receive it, in any medium, provided that you\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"conspicuously and appropriately publish on each copy an appropriate\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"copyright notice and disclaimer of warranty; keep intact all the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"notices that refer to this License and to the absence of any warranty;\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"and give any other recipients of the Program a copy of this License\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"along with the Program.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"You may charge a fee for the physical act of transferring a copy, and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"you may at your option offer warranty protection in exchange for a fee.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  2. You may modify your copy or copies of the Program or any portion\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"of it, thus forming a work based on the Program, and copy and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distribute such modifications or work under the terms of Section 1\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"above, provided that you also meet all of these conditions:\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    a) You must cause the modified files to carry prominent notices\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    stating that you changed the files and the date of any change.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    b) You must cause any work that you distribute or publish, that in\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    whole or in part contains or is derived from the Program or any\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    part thereof, to be licensed as a whole at no charge to all third\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    parties under the terms of this License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    c) If the modified program normally reads commands interactively\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    when run, you must cause it, when started running for such\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    interactive use in the most ordinary way, to print or display an\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    announcement including an appropriate copyright notice and a\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    notice that there is no warranty (or else, saying that you provide\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    a warranty) and that users may redistribute the program under\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    these conditions, and telling the user how to view a copy of this\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    License.  (Exception: if the Program itself is interactive but\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    does not normally print such an announcement, your work based on\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    the Program is not required to print an announcement.)\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"These requirements apply to the modified work as a whole.  If\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"identifiable sections of that work are not derived from the Program,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"and can be reasonably considered independent and separate works in\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"themselves, then this License, and its terms, do not apply to those\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"sections when you distribute them as separate works.  But when you\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distribute the same sections as part of a whole which is a work based\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"on the Program, the distribution of the whole must be on the terms of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"this License, whose permissions for other licensees extend to the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"entire whole, and thus to each and every part regardless of who wrote it.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Thus, it is not the intent of this section to claim rights or contest\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"your rights to work written entirely by you; rather, the intent is to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"exercise the right to control the distribution of derivative or\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"collective works based on the Program.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"In addition, mere aggregation of another work not based on the Program\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"with the Program (or with a work based on the Program) on a volume of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"a storage or distribution medium does not bring the other work under\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the scope of this License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  3. You may copy and distribute the Program (or a work based on it,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"under Section 2) in object code or executable form under the terms of\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Sections 1 and 2 above provided that you also do one of the following:\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    a) Accompany it with the complete corresponding machine-readable\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    source code, which must be distributed under the terms of Sections\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    1 and 2 above on a medium customarily used for software interchange; or,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    b) Accompany it with a written offer, valid for at least three\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    years, to give any third party, for a charge no more than your\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    cost of physically performing source distribution, a complete\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    machine-readable copy of the corresponding source code, to be\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    distributed under the terms of Sections 1 and 2 above on a medium\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    customarily used for software interchange; or,\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    c) Accompany it with the information you received as to the offer\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    to distribute corresponding source code.  (This alternative is\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    allowed only for noncommercial distribution and only if you\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    received the program in object code or executable form with such\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"    an offer, in accord with Subsection b above.)\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"The source code for a work means the preferred form of the work for\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"making modifications to it.  For an executable work, complete source\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"code means all the source code for all modules it contains, plus any\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"associated interface definition files, plus the scripts used to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"control compilation and installation of the executable.  However, as a\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"special exception, the source code distributed need not include\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"anything that is normally distributed (in either source or binary\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"form) with the major components (compiler, kernel, and so on) of the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"operating system on which the executable runs, unless that component\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"itself accompanies the executable.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"If distribution of executable or object code is made by offering\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"access to copy from a designated place, then offering equivalent\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"access to copy the source code from the same place counts as\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distribution of the source code, even though third parties are not\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"compelled to copy the source along with the object code.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  4. You may not copy, modify, sublicense, or distribute the Program\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"except as expressly provided under this License.  Any attempt\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"otherwise to copy, modify, sublicense or distribute the Program is\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"void, and will automatically terminate your rights under this License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"However, parties who have received copies, or rights, from you under\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"this License will not have their licenses terminated so long as such\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"parties remain in full compliance.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  5. You are not required to accept this License, since you have not\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"signed it.  However, nothing else grants you permission to modify or\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distribute the Program or its derivative works.  These actions are\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"prohibited by law if you do not accept this License.  Therefore, by\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"modifying or distributing the Program (or any work based on the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"Program), you indicate your acceptance of this License to do so, and\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"all its terms and conditions for copying, distributing or modifying\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the Program or works based on it.\n"
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
literal|"Program), the recipient automatically receives a license from the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"original licensor to copy, distribute or modify the Program subject to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"these terms and conditions.  You may not impose any further\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"restrictions on the recipients' exercise of the rights granted herein.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"You are not responsible for enforcing compliance by third parties to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"this License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  7. If, as a consequence of a court judgment or allegation of patent\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"infringement or for any other reason (not limited to patent issues),\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"conditions are imposed on you (whether by court order, agreement or\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"otherwise) that contradict the conditions of this License, they do not\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"excuse you from the conditions of this License.  If you cannot\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"distribute so as to satisfy simultaneously your obligations under this\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"License and any other pertinent obligations, then as a consequence you\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"may not distribute the Program at all.  For example, if a patent\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"license would not permit royalty-free redistribution of the Program by\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"all those who receive copies directly or indirectly through you, then\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the only way you could satisfy both it and this License would be to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"refrain entirely from distribution of the Program.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"If any portion of this section is held invalid or unenforceable under\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"any particular circumstance, the balance of the section is intended to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"apply and the section as a whole is intended to apply in other\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"circumstances.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"It is not the purpose of this section to induce you to infringe any\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"patents or other property right claims or to contest validity of any\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"such claims; this section has the sole purpose of protecting the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"integrity of the free software distribution system, which is\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"implemented by public license practices.  Many people have made\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"generous contributions to the wide range of software distributed\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"through that system in reliance on consistent application of that\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"system; it is up to the author/donor to decide if he or she is willing\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"to distribute software through any other system and a licensee cannot\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"impose that choice.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"This section is intended to make thoroughly clear what is believed to\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"be a consequence of the rest of this License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  8. If the distribution and/or use of the Program is restricted in\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"certain countries either by patents or by copyrighted interfaces, the\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"original copyright holder who places the Program under this License\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"may add an explicit geographical distribution limitation excluding\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"those countries, so that distribution is permitted only in or among\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"countries not thus excluded.  In such case, this License incorporates\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"the limitation as if written in the body of this License.\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"  9. The Free Software Foundation may publish revised and/or new versions\n"
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
literal|"specifies a version number of this License which applies to it and \"any\n"
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
literal|"this License, you may choose any version ever published by the Free Software\n"
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
literal|"  10. If you wish to incorporate parts of the Program into other free\n"
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
name|show_warranty_command
parameter_list|(
name|ignore
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|ignore
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
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
literal|"  11. BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY\n"
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
literal|"  12. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING\n"
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
name|add_cmd
argument_list|(
literal|"copying"
argument_list|,
name|no_class
argument_list|,
name|show_copying_command
argument_list|,
literal|"Conditions for redistributing copies of GDB."
argument_list|,
operator|&
name|showlist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"warranty"
argument_list|,
name|no_class
argument_list|,
name|show_warranty_command
argument_list|,
literal|"Various kinds of warranty you do not have."
argument_list|,
operator|&
name|showlist
argument_list|)
expr_stmt|;
comment|/* For old-timers, allow "info copying", etc.  */
name|add_info
argument_list|(
literal|"copying"
argument_list|,
name|show_copying_command
argument_list|,
literal|"Conditions for redistributing copies of GDB."
argument_list|)
expr_stmt|;
name|add_info
argument_list|(
literal|"warranty"
argument_list|,
name|show_warranty_command
argument_list|,
literal|"Various kinds of warranty you do not have."
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

