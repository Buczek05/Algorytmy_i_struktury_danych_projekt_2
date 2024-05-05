from matplotlib import pyplot as plt

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


def generate_graphs_for_files(save_file_name: str, files: tuple[str]) -> None:
    fig, ax = plt.subplots()
    for file_name in files:
        with open("../result/" + file_name, "r") as file:
            data = [line.strip().split(";") for line in file.readlines()]
        x = [int(line[0]) for line in data]
        y = [int(line[1]) for line in data]
        sort_func = file_name.split("-")[-1]
        ax.plot(x, y, label=sort_func, color=color_for_type[sort_func])
    ax.legend()
    fig.savefig(f"../result/{save_file_name}.jpg", dpi=1000)


if __name__ == "__main__":
    for key, files in graphs_files.items():
        generate_graphs_for_files(key, files)
