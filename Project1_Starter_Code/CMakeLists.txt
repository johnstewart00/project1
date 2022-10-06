cmake_minimum_required(VERSION 3.16.3)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h CommaAutomaton.cpp CommaAutomaton.h PeriodAutomaton.cpp PeriodAutomaton.h Q_MarkAutomaton.cpp Q_MarkAutomaton.h LeftParenAutomaton.cpp LeftParenAutomaton.h RightParen.cpp RightParen.h Multiply.cpp Multiply.h Add.cpp Add.h Schemes.cpp Schemes.h Facts.cpp Facts.h Rules.cpp Rules.h Queries.cpp Queries.h IDAutomaton.cpp IDAutomaton.h stringAutomaton.cpp stringAutomaton.h commentAutomaton.cpp commentAutomaton.h undefinedAutomaton.cpp undefinedAutomaton.h)
