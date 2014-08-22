*** Settings ***
Library           coverageLibrary.py

*** Test Case ***
Validate Percentage
    [Template]    Check Valid Percentage
    10    
    20     
    30
    100

Invalid Percentage should fail
    [Template]    Check InValid Percentage
    120
    140

*** Keyword ***
Check Valid Percentage
    [Arguments]    ${value} 
    Check Percentage    ${value}

Check InValid Percentage
    [Arguments]    ${value} 
    Run Keyword And Expect Error    Value > 100 (given ${value})    Check Percentage    ${value}
