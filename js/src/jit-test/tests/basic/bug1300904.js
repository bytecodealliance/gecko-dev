Object.getOwnPropertyNames(this);
oomTest(function() {
    this[0] = null;
    Object.freeze(this);
});
