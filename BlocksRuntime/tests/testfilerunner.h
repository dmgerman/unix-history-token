begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  testfilerunner.h
end_comment

begin_comment
comment|//  testObjects
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Blaine Garst on 9/24/08.
end_comment

begin_comment
comment|//
end_comment

begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty

begin_comment
comment|/*     variations:         four source types:  C, ObjC, C++, ObjC++,           and for ObjC or ObjC++ we have              RR and GC capabilities         we assume C++ friendly includes for C/ObjC even if C++ isn't used                                     four compilers: C, ObjC, C++, ObjC++           and for ObjC or ObjC++ we can compile               RR, RR+GC, GC+RR, GC           although to test RR+GC we need to build a shell "main" in both modes           and/or run with GC disabled if possible.                    To maximize coverage we mark files with capabilities and then ask them to be     compiled with each variation of compiler and option.     If the file doesn't have the capability it politely refuses. */
end_comment

begin_enum
enum|enum
name|options
block|{
name|Do64
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|DoCPP
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|DoOBJC
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|DoGC
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|DoRR
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|DoRRGC
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|// -fobjc-gc but main w/o so it runs in RR mode
name|DoGCRR
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
comment|// -fobjc-gc& run GC mode
comment|//DoDashG = (1<< 8),
name|DoDashO
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|DoDashOs
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|DoDashO2
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|DoC99
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
comment|// -std=c99
block|}
enum|;
end_enum

begin_decl_stmt
unit|@
name|class
name|TestFileExeGenerator
decl_stmt|;
end_decl_stmt

begin_comment
comment|// this class will actually compile and/or run a target binary
end_comment

begin_comment
comment|// XXX we don't track which dynamic libraries requested/used nor set them up
end_comment

begin_decl_stmt
unit|@
name|interface
name|TestFileExe
range|:
name|NSObject
block|{
name|NSPointerArray
operator|*
name|compileLine
block|;
name|int
name|options
block|;
name|bool
name|shouldFail
block|;
name|TestFileExeGenerator
operator|*
name|generator
block|;
specifier|__strong
name|char
operator|*
name|binaryName
block|;
specifier|__strong
name|char
operator|*
name|sourceName
block|;
specifier|__strong
name|char
operator|*
name|libraryPath
block|;
specifier|__strong
name|char
operator|*
name|frameworkPath
block|; }
expr|@
name|property
name|int
name|options
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|assign
argument_list|)
end_macro

begin_decl_stmt
name|NSPointerArray
modifier|*
name|compileLine
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|assign
argument_list|)
end_macro

begin_decl_stmt
name|TestFileExeGenerator
modifier|*
name|generator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
name|bool
name|shouldFail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|binaryName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|sourceName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|libraryPath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|frameworkPath
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|bool
operator|)
name|compileUnlessExists
operator|:
operator|(
name|bool
operator|)
name|skip
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|bool
operator|)
name|run
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|property
argument_list|(
name|readonly
argument_list|)
specifier|__strong
name|char
operator|*
name|radar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
comment|// this class generates an appropriate set of configurations to compile
comment|// we don't track which gcc we use but we should XXX
expr|@
name|interface
name|TestFileExeGenerator
operator|:
name|NSObject
block|{
name|bool
name|hasObjC
block|;
name|bool
name|hasRR
block|;
name|bool
name|hasGC
block|;
name|bool
name|hasCPlusPlus
block|;
name|bool
name|wantsC99
block|;
name|bool
name|wants64
block|;
name|bool
name|wants32
block|;
name|bool
name|supposedToNotCompile
block|;
name|bool
name|open
block|;
comment|// this problem is still open - e.g. unresolved
specifier|__strong
name|char
operator|*
name|radar
block|;
comment|// for things already known to go wrong
specifier|__strong
name|char
operator|*
name|filename
block|;
specifier|__strong
name|char
operator|*
name|compilerPath
block|;
specifier|__strong
name|char
operator|*
name|errorString
block|;
specifier|__strong
name|char
operator|*
name|warningString
block|;
name|NSPointerArray
operator|*
name|extraLibraries
block|; }
expr|@
name|property
name|bool
name|hasObjC
operator|,
name|hasRR
operator|,
name|hasGC
operator|,
name|hasCPlusPlus
operator|,
name|wantsC99
operator|,
name|supposedToNotCompile
operator|,
name|open
operator|,
name|wants32
operator|,
name|wants64
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|property
argument_list|(
name|assign
argument_list|)
specifier|__strong
name|char
operator|*
name|radar
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|compilerPath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|errorString
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
specifier|__strong
name|char
modifier|*
name|warningString
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|TestFileExe
operator|*
operator|)
name|lineForOptions
operator|:
operator|(
name|int
operator|)
name|options
expr_stmt|;
end_expr_stmt

begin_comment
comment|// nil if no can do
end_comment

begin_expr_stmt
operator|+
operator|(
name|NSArray
operator|*
operator|)
name|generatorsFromFILE
operator|:
operator|(
name|FILE
operator|*
operator|)
name|fd
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|NSArray
operator|*
operator|)
name|generatorsFromPath
operator|:
operator|(
name|NSString
operator|*
operator|)
name|path
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

