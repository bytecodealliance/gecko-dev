// |jit-test| --fuzzing-safe; --baseline-eager; --arm-hwcap=vfp; skip-if: getBuildConfiguration('pbl')
function f() {};
f();
f();
f();
try {
    print(disnative(f));
} catch (e) {}
