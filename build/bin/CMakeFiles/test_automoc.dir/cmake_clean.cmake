FILE(REMOVE_RECURSE
  "clientprovider_automoc.cpp"
  "lssprovider_automoc.cpp"
  "serverprovider_automoc.cpp"
  "test_automoc.cpp"
  "CMakeFiles/test_automoc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/test_automoc.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
