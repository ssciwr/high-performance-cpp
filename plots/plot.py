#!/usr/bin/env python
# coding: utf-8

# to use:
# 1. generate a json file, e.g. ./build/bench --benchmark_out=gcc.json
# 2. generate plots, e.g. ./plot.py gcc.json

import pandas as pd
import json
from matplotlib import pyplot as plt
import sys

filename = sys.argv[1]
name = filename.split(".")[0]

# load benchmarks data
df = pd.DataFrame(json.load(open(filename))["benchmarks"])

# only keep names with /, i.e. drop avg/rms/etc entries
df = df.loc[df.name.str.contains("/")]

# create a column with complexity n
df["n"] = df.name.apply(lambda x: x.split("/")[1]).astype("uint32")

# create a column with simplified name
df["benchmark"] = df.name.apply(lambda x: x.split("/")[0][6:])

# only keep name, cpu_time and n columns
df = df[["benchmark", "n", "cpu_time"]]

# plot results
for basename in ["data_structure", "matmul", "particles_m", "particles_xy", "dist"]:
    fig, ax = plt.subplots(ncols=1, figsize=(12, 6))
    for benchmark, data in df.loc[df.benchmark.str.contains(basename)].groupby(
        "benchmark"
    ):
        data.plot(ax=ax, x="n", y="cpu_time", label=benchmark[(len(basename) + 1) :])
    plt.title(basename)
    plt.title(f"{basename} runtime ({name})")
    plt.xscale("log")
    plt.xlabel("number of items")
    plt.yscale("log")
    plt.ylabel("runtime (ns)")
    plt.legend()
    fig.savefig(f"{basename}-{name}.png", bbox_inches="tight", dpi=120)
