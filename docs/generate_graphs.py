import math

from matplotlib import pyplot as plt, ticker

graphs_files = {
    "test_1-group_1": (
        "test_1-Bubble Sort",
        "test_1-Insert Sort",
        "test_1-Selection Sort",
    ),
    "test_1-group_2": ("test_1-Heap Sort", "test_1-Quick Sort", "test_1-Shell Sort"),
    "test_1-both": (
        "test_1-Bubble Sort",
        "test_1-Insert Sort",
        "test_1-Selection Sort",
        "test_1-Heap Sort",
        "test_1-Quick Sort",
        "test_1-Shell Sort",
    ),
    "test_2-group_1": (
        "test_2-Bubble Sort",
        "test_2-Insert Sort",
        "test_2-Selection Sort",
    ),
    "test_2-group_2": ("test_2-Heap Sort", "test_2-Quick Sort", "test_2-Shell Sort"),
    "test_2-both": (
        "test_2-Bubble Sort",
        "test_2-Insert Sort",
        "test_2-Selection Sort",
        "test_2-Heap Sort",
        "test_2-Quick Sort",
        "test_2-Shell Sort",
    ),
    "test_3-group_1": (
        "test_3-Bubble Sort",
        "test_3-Insert Sort",
        "test_3-Selection Sort",
    ),
    "test_3-group_2": ("test_3-Heap Sort", "test_3-Quick Sort", "test_3-Shell Sort"),
    "test_3-both": (
        "test_3-Bubble Sort",
        "test_3-Insert Sort",
        "test_3-Selection Sort",
        "test_3-Heap Sort",
        "test_3-Quick Sort",
        "test_3-Shell Sort",
    ),
}

color_for_type = {
    "Bubble Sort": "green",
    "Insert Sort": "blue",
    "Selection Sort": "red",
    "Heap Sort": "purple",
    "Quick Sort": "orange",
    "Shell Sort": "yellow",
}

computational_complexity = {
    "Bubble Sort": (lambda n: n ** 2, lambda n: n ** 2, lambda n: n),
    "Insert Sort": (lambda n: n ** 2, lambda n: n ** 2, lambda n: n),
    "Selection Sort": (lambda n: n ** 2, lambda n: n ** 2, lambda n: n),
    "Heap Sort": (lambda n: n * math.log(n), lambda n: n * math.log(n), lambda n: n),
    "Quick Sort": (lambda n: n * math.log(n), lambda n: n ** 2, lambda n: n * math.log(n)),
    "Shell Sort": (lambda n: n ** (3 / 2), lambda n: n ** (3 / 2), lambda n: n),
}


def generate_graphs_for_files(save_file_name: str, files: tuple[str]) -> None:
    fig, ax = plt.subplots()
    for file_name in files:
        with open("../result/" + file_name, "r") as file:
            data = [line.strip().split(";") for line in file.readlines()]
        x = [int(line[0]) for line in data]
        y = [int(line[1]) for line in data]
        sort_func = file_name.split("-")[-1]
        ax.plot(x, y, label=sort_func, color=color_for_type[sort_func])
        o_algorithm = computational_complexity[sort_func][int(file_name.split("-")[0][-1]) - 1]
        y_calculated = []
        time_per_n = y[-1] / o_algorithm(x[-1])
        for _x in x:
            y_calculated.append(o_algorithm(_x) * time_per_n)
        ax.plot(x, y_calculated, label="O(n) for " + sort_func, color=color_for_type[sort_func], linestyle='dotted')

    ax.yaxis.set_major_formatter(ticker.ScalarFormatter(useMathText=True))
    ax.legend()
    fig.savefig(f"../result/{save_file_name}.jpg", dpi=1000)


if __name__ == "__main__":
    for key, files in graphs_files.items():
        generate_graphs_for_files(key, files)
